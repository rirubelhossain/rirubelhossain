int witness(int a, int n)
{
int x, d=1, i = ceil(log(n - 1.0) / log(2.0)) - 1;
for ( ; i >= 0; i--) {
x = d; d = (d * d) % n;
if (d==1 && x!=1 && x!=n-1) return 1;
if (((n-1) & (1<<i)) > 0) d = (d * a) % n;
}
return (d == 1 ? 0 : 1);
}
int miller(int n, int s = 50)
{
if (n == 2) return 1;
if ((n % 2) == 0) return 0;
int j, a;
for (j = 0; j < s; j++) {
a = rand() * (n-2) / RAND_MAX + 1;
if (witness(a, n)) return 0;
}
return 1;
}

//Probabilistic test, quickly gives the answer. Answer is not correct for all the numbers.
//Returns a divider or 1 if the divisor was not found.

template <class T>
T pollard_p_1 (T n)
{
	const T b = 13;
	const T q[] = { 2, 3, 5, 7, 11, 13 };

	T a = 5 % n;
	for (int j=0; j<10; j++)
	{
		while (gcd (a, n) != 1)
		{
			mulmod (a, a, n);
			a += 3;
			a %= n;
		}

		for (size_t i = 0; i < sizeof q / sizeof q[0]; i++)
		{
			T qq = q[i];
			T e = (T) floor (log ((double)b) / log ((double)qq));
			T aa = powmod (a, powmod (qq, e, n), n);
			if (aa == 0)
				continue;
			
			T g = gcd (aa-1, n);
			if (1 < g && g < n)
				return g;
		}

	}

	//If nothing found
	return 1;

}

//Probabilistic test, quickly gives the answer. Answer is not correct for all the numbers.
//Returns a divider or 1 if the divisor was not found.
template <class T>
T pollard_rho (T n, unsigned iterations_count = 100000)
{
	T
		b0 = rand() % n,
		b1 = b0,
		g;
	mulmod (b1, b1, n);
	if (++b1 == n)
		b1 = 0;
	g = gcd (abs (b1 - b0), n);
	for (unsigned count=0; count<iterations_count && (g == 1 || g == n); count++)
	{
		mulmod (b0, b0, n);
		if (++b0 == n)
			b0 = 0;
		mulmod (b1, b1, n);
		++b1;
		mulmod (b1, b1, n);
		if (++b1 == n)
			b1 = 0;
		g = gcd (abs (b1 - b0), n);
	}
	return g;
}

//Probabilistic test, quickly gives the answer. Answer is not correct for all the numbers.
//Returns a divider or 1 if the divisor was not found.
template <class T>
T pollard_bent (T n, unsigned iterations_count = 19)
{
	T
		b0 = rand() % n,
		b1 = (b0*b0 + 2) % n,
		a = b1;
	for (unsigned iteration=0, series_len=1; iteration<iterations_count; iteration++, series_len*=2)
	{
		T g = gcd (b1-b0, n);
		for (unsigned len=0; len<series_len && (g==1 && g==n); len++)
		{
			b1 = (b1*b1 + 2) % n;
			g = gcd (abs(b1-b0), n);
		}
		b0 = a;
		a = b1;
		if (g != 1 && g != n)
			return g;
	}
	return 1;
}

//Probabilistic test, quickly gives the answer. Answer is not correct for all the numbers.
//Returns a divider or 1 if the divisor was not found.
template <class T>
T pollard_monte_carlo (T n, unsigned m = 100)
{
	T b = rand() % (m-2) + 2;

	static std::vector<T> primes;
	static T m_max;
	if (primes.empty())
		primes.push_back (3);
	if (m_max < m)
	{
		m_max = m;
		for (T prime=5; prime<=m; ++++prime)
		{
			bool is_prime = true;
			for (std::vector<T>::const_iterator iter=primes.begin(), end=primes.end();
				iter!=end; ++iter)
			{
				T div = *iter;
				if (div*div > prime)
					break;
				if (prime % div == 0)
				{
					is_prime = false;
					break;
				}
			}
			if (is_prime)
				primes.push_back (prime);
		}
	}

	T g = 1;
	for (size_t i=0; i<primes.size() && g==1; i++)
	{
		T cur = primes[i];
		while (cur <= n)
			cur *= primes[i];
		cur /= primes[i];
		b = powmod (b, cur, n);
		g = gcd (abs(b-1), n);
		if (g == n)
			g = 1;
	}

	return g;
}

//This method is one hundred percent, but it can be very slow if the number has small divisors. 
//So run it is only after all other methods.
template <class T, class T2>
T ferma (const T & n, T2 unused)
{
	T2
		x = sq_root (n),
		y = 0,
		r = x*x - y*y - n;
	for (;;)
		if (r == 0)
			return x!=y ? x-y : x+y;
		else
			if (r > 0)
			{
				r -= y+y+1;
				++y;
			}
			else
			{
				r += x+x+1;
				++x;
			}
}

//This elementary method is useful for very small divisors
template <class T, class T2>
T2 prime_div_trivial (const T & n, T2 m)
{
	if (n == 2 || n == 3)
		return 1;
	if (n < 2)
		return 0;
	if (even (n))
		return 2;

	T2 pi;
	const vector<T2> & primes = get_primes (m, pi);

	for (std::vector<T2>::const_iterator iter=primes.begin(), end=primes.end();
		iter!=end; ++iter)
	{
		const T2 & div = *iter;
		if (div * div > n)
			break;
		else
			if (n % div == 0)
				return div;
	}
	
	if (n < m*m)
		return 1;
	return 0;

}

//putting it altogether
template <class T, class T2>
void factorize (const T & n, std::map<T,unsigned> & result, T2 unused)
{
	if (n == 1)
		;
	else
		if (isprime (n))
			++result[n];
		else
			if (n < 1000*1000)
			{
				T div = prime_div_trivial (n, 1000);
				++result[div];
				factorize (n / div, result, unused);
			}
			else
			{
				T div;
				div = pollard_monte_carlo (n);
				if (div == 1)
					div = pollard_rho (n);
				if (div == 1)
					div = pollard_p_1 (n);
				if (div == 1)
					div = pollard_bent (n);
				if (div == 1)
					div = ferma (n, unused);
				factorize (div, result, unused);
				factorize (n / div, result, unused);
			}
}

