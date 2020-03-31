for(i=0;i<n;i++)
{
	id=i;
	for(j=i+1;j<n;j++)
		if( fabs(mat[j][i]) > fabs(mat[id][i]) )
			id = j;

	if(id!=i)
	{
		for(j=i;j<=n;j++)
			swap(mat[i][j],mat[id][j]);
	}


	for(j=0;j<n;j++) if(j!=i)
	{
		factor = mat[j][i]/mat[i][i];

		for(k=i;k<=n;k++)
			mat[j][k] -= factor*mat[i][k];
	}
}


//Independent variable 0-1
int gauss()
{
	int i, j, id, k;
	int ans=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d",mat[i][j]);
		printf("\n");
	}

	id = 0;
	for(i=0;i<m;i++)
	{
		for(j=id;j<n;j++)
			if( mat[j][i] )
				break;

		if(j==n) continue;

		if(id!=j)
		{
			for(k=0;k<m;k++)
				swap(mat[j][k],mat[id][k]);
		}


		for(j=0;j<n;j++) if(j!=id && mat[j][i])
		{
			for(k=i;k<m;k++)
				mat[j][k] ^= mat[id][k];
		}

		id++;
	}

	return ans<<id;
}
