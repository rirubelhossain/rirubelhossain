#include<stdio.h>
#include<vector>
using namespace std;

//Primitive root modulo n (Primitive root modulo  n) Is called a number g That all its powers modulo n runs over all numbers relatively prime to  n.
//if g is a primitive root modulo  n, Then for any integer a such that gcd(a,n)=1 , There exists an integer k That g^k = a (mod n). 


//Primitive root exists if, n = 1, 2, 4, p^k or 2p^k

__int64 powmod ( __int64 a, __int64 b, int p )
{
	__int64 res = 1;

	while ( b )
	{
		if ( b & 1 )
			res = ( res * a ) % p  , -- b ;
		else
			a = ( a * a ) % p , b >>= 1 ;
	}

	return res;
}

//finds primitive root of a prime.
//for any number replace phi with original phi

int generator ( int p )
{
	vector < int > fact ;

	int phi = p - 1, n = phi ;

	
	for ( int i = 2 ; i * i <= n ; ++ i )
		if ( n % i == 0 )
		{
			fact.push_back ( i ) ;

			while ( n % i == 0 )
				n /= i ;
		}

	if ( n > 1 )
		fact. push_back ( n ) ;

	for ( int res = 2 ; res <= p ; ++ res )
	{
		bool ok = true ;
		
		for ( size_t i = 0 ; i < fact. size ( ) && ok ; ++ i )
			ok &= ( powmod(res,phi/fact[i],p) != 1 ) ;

		if ( ok ) return res ;
	}

	return - 1 ;
}

int main()
{
	printf("%I64d\n",powmod(13,1000000007,1000000009));
	printf("%d\n",generator(1000000009));

	return 0;
}