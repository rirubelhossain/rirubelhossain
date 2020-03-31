//(1^k + 2^k + .... + n^k) % MOD= ?

LL MOD = 1000000007;
map<PII, LL> M;

LL ncr[55][55];

LL f(int n, int k)
{
	if(n==1) return 1;
	if(k==0) return n;
	if(M.find(PII(n,k))!=M.end()) return M[PII(n,k)];

	LL ret = 0, temp, z;
	int i;
	
	if(n%2)
	{
		ret = f(n-1,k);

		temp = 1;
		for(i=1;i<=k;i++)
			temp = (temp * n)%MOD;
		
		ret = (ret + temp)%MOD;
		
		return M[PII(n,k)] = ret;
	}

	temp = 1;
	for(i=1;i<=k;i++)
		temp = (temp*2)%MOD;
	
	ret = (temp*f(n/2,k))%MOD;
	
	temp = 1;
	for(i=0;i<=k;i++)
	{
		z = (ncr[k][i]*((temp*f(n/2,i))%MOD))%MOD;
		if( (k-i)%2 )
			z = MOD - z;
		ret = (ret + z)%MOD;
		temp = (temp*2)%MOD;
	}

	return M[PII(n,k)] = ret;

}

void gen()
{
	ncr[0][0]=1;
	int limncr = 50;
	int i, j;
	for(i=1;i<=limncr;i++)
		for(j=0;j<=limncr;j++)
		{
			if(j>i) ncr[i][j]=0;
			else if(j==i || j==0) ncr[i][j]=1;
			else ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%MOD;
		}
}

int value(int n, int k)
{
	gen();
	return f(n,k);
}

