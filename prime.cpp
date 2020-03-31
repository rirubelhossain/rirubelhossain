vector<int> Prime;
int mark[1000002];

void sieve(int n)
{
	int i,j,limit=sqrt(n*1.)+2;

	mark[1] = 1;
	for(i=4;i<=n;i+=2) mark[i]=1;

	Prime.push_back(2);
	for(i=3;i<=n;i+=2)
		if(!mark[i])
		{
			Prime.push_back(i);

			if(i<=limit)
			{
				for(j=i*i;j<=n;j+=i*2)
				{
					mark[j] = 1;
				}
			}
		}
}


//Linear sieve
const int N = 10000000;
int lp[N+1];
vector<int> pr;
 
for (int i=2; i<=N; ++i) {
	if (lp[i] == 0) {
		lp[i] = i;
		pr.push_back (i);
	}
	for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
		lp[i * pr[j]] = pr[j];
}

/**************************
 * Sieve of Erastosthenes * (fast, memory efficient version)
 **************************
 * Does some magic, after which gP(n) is non-zero iff n is
 * prime. N is the value of the largest prime you will need.
 * Requires N / 16 bytes of memory.
 * WARNING! Only works for odd numbers; deal with even numbers 
 * yourself!
 * If that is unacceptable, add "n==2||(n&1)&&" after the
 * first bracket in the gP() macro.
 * #include <string.h>
 * #include <math.h>
 **/
#define N 51000000
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
    memset( prime, -1, sizeof( prime ) );

    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
}
