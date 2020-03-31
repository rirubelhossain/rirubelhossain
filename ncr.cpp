ncr[0][0]=1;
int limncr = 10;
for(i=1;i<=limncr;i++)
	for(j=0;j<=limncr;j++)
	{
		if(j>i) ncr[i][j]=0;
		else if(j==i || j==0) ncr[i][j]=1;
		else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
	}


int C (int n, int k) {
	double res = 1;
	for (int i=1; i<=k; ++i)
		res = res * (n-k+i) / i;
	return (int) (res + 0.01);
}

