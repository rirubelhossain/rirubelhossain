//O(sqrtN)
int f_phi(int n) 
{
	int result = n;
	for (int i = 2; i * i <= n; i++)
		if (n%i == 0)
		{
			while (n%i == 0) n /= i;
			result -= result/i;
		}
		
		if (n > 1) result -= result/n; 
		return result;
} 








//O(NlgN)
int phi[1000],mark[1000];

void sievephi(int n)
{
	int i,j;

	for(i=1;i<=n;i++) phi[i]=i;

	phi[1]=1;
	mark[1] = 1;

	for(i=2;i<=n;i+=2)
	{
		if(i!=2) mark[i]=1;
		phi[i] = phi[i]/2;
	}

	for(i=3;i<=n;i+=2)
		if(!mark[i])
		{
			phi[i] = phi[i] - 1;

			for(j=2*i;j<=n;j+=i)
			{
				mark[j] = 1;
				phi[j] = phi[j]/i*(i-1);
			}
		}
}
