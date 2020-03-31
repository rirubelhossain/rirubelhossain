int p[]={2,3,11,2089,7253};
LL MOD = 1000000123;

LL BigMod(LL a, LL b, LL m)
{
	if(a==0) return 0;
	if(b==0) return 1;

	LL x = BigMod(a,b/2,m);

	x = (x*x)%m;
	if(b&1) x = (x*a)%m;

	return x;
}

int nCr(int n, int r, int m)
{
	if(r>n-r) r = n-r;

	if(n==0 && r==0) return 1;
	if(r>n) return 0;
	if(r<0) return 0;
	if(r==0 || r==n) return 1;

	int i, ans = 1;
	for(i=1;i<=r;i++)
	{
		ans = (ans * (n-i+1))%m;
		ans = (ans * BigMod(i, m-2, m))%m;
	}

	return ans;
}

int CatalanModPrime(int N, int p)
{
	int lob, hor;

	lob = 2*N;
	hor = N;

	int ans = 1;

	while(1)
	{
		ans = (ans * nCr(lob%p, hor%p, p))%p;
		lob/=p;
		hor/=p;

		if(lob==0) break;
	}

	lob = 2*N;
	hor = N+1;

	int ans2 = 1;
	while(1)
	{
		ans2 = (ans2 * nCr(lob%p, hor%p, p))%p;
		lob/=p;
		hor/=p;

		if(lob==0) break;
	}

	return (ans-ans2+p)%p;
}

//returns Nth Catalan%Nonprime
//Prime factors of Nonprime in p
int f1(int N)
{
	LL m, a[10];
	int i, j;

	for(i=0;i<5;i++)
	{
		a[i] = CatalanModPrime(N, p[i]);
	}

	//Chinese remainder theorem
	LL ans = 0;
	for(i=0;i<5;i++)
	{
		m = 1;
		for(j=0;j<5;j++) if(i!=j)
			m = (m*p[j]);

		ans = (ans + ((a[i]*m)%(MOD-1))*BigMod(m, p[i]-2, p[i]))%(MOD-1);
	}

	return ans;
}
