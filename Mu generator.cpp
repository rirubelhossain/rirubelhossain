int mark[1000002];
vector<LL> Z;
int mu[1000002];
int sz;

//mu[2] = 1, mu[3] = 1, mu[6] = -1
void sieve(int n)
{
	LL i,j,limit=sqrt(n*1.)+2;

	for(i=1;i<=n;i++) mu[i] = -1;

	mark[1] = 1;
	mu[2]*=-1;
	for(i=4;i<=n;i+=2) 
	{
		if(i%4==0) mu[i] = 0;
		else mu[i]*=-1;
		mark[i]=1;
	}

	Z.push_back(2);
	for(i=3;i<=n;i++)
	{
		if(mu[i]) Z.push_back(i);

		if(mark[i]) continue;

		mu[i]*=-1;
		for(j=2*i;j<=n;j+=i)
		{
			mark[j] = 1;
			if(j%(i*i)==0) mu[j] = 0;
			else mu[j]*=-1;
		}
	}

	sz = SZ(Z);
}
