//Recursive O(n) 1-based implementation
int joseph ( int n, int k ) 
{ 
	return n > 1 ? ( joseph ( n - 1, k ) + k - 1 ) % n + 1 : 1 ; 
}

//Non recursive O(n) 1-based implementation
int joseph (int n, int k) 
{
	 int res = 0;
	 for (int i = 1; i <= n; ++ i)
		 res = (res + k)% i;
	 return res + 1;
}

//Recursive O(klogn) 0-based implementation
int joseph ( int n, int k ) 
{ 
	if ( n == 1 ) return 0 ; 
	if ( k == 1 ) return n - 1 ; 
	
	if ( k > n ) 
		return ( joseph ( n - 1, k ) + k ) % n ; 
	
	int cnt = n / k ; 
	int res = joseph ( n - cnt, k ) ; 
	res - = n % k ; 
	
	if ( res < 0 ) 
		res + = n ; 
	else 
		res + = res / ( k - 1 ) ; 
	
	return res ; 
}

//inverse josephus
int invJosephus(int n, int m, int x) {
 for (int i = n; ; i--) {
 if (x == i) return n - i;
 x = (x - m % i + i) % i;
 }
 }
