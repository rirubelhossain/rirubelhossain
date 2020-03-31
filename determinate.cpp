double factor,det;
int id;
det=1;
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

	if( (id - i)%2 ) det*=-1;

	det*=mat[i][i];

	for(j=0;j<n;j++) if(j!=i)
	{
		factor = mat[j][i]/mat[i][i];

		for(k=i;k<=n;k++)
			mat[j][k] -= factor*mat[i][k];
	}
}






//MODULAR DET
LL mat[55][55];
LL MOD =121547;
int n;

LL BigMod(LL a, LL b)
{
	a = a%MOD;
	if(b==0) return 1;
	LL x = BigMod(a,b/2);
	x = (x*x)%MOD;
	if(b&1) x = (x*a)%MOD;
	return x; 
}


int determinant()
{
	LL factor,det,y;
	int id,i,j,k;
	det=1;

	for(i=0;i<n;i++)
	{
		id=i;
		for(j=i+1;j<n;j++)
			if( ABS(mat[j][i]) > ABS(mat[id][i]) )
				id = j;

		if(id!=i)
		{
			for(j=i;j<n;j++)
				swap(mat[i][j],mat[id][j]);
			det = (MOD - det)%MOD;
		}


		det = (det * mat[i][i])%MOD;

		for(j=0;j<n;j++) if(j!=i)
		{
			factor = (mat[j][i]*BigMod(mat[i][i],MOD-2))%MOD;

			for(k=i;k<n;k++)
			{
				y = (factor*mat[i][k])%MOD;
				mat[j][k] = (mat[j][k] + MOD - y)%MOD;
			}
		}
	}

	return det;
}
