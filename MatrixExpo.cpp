typedef  unsigned int LL;

#define MAX_DIM 55

struct Matrix
{
	LL m[MAX_DIM][MAX_DIM];
	int DIM;

	Matrix(){}

	Matrix(int n)
	{
		DIM = n;
		int i, j;

		for(i=0;i<DIM;i++)
			for(j=0;j<DIM;j++)
				m[i][j] = 0;
	}

	Matrix operator*(Matrix &A)
	{
		Matrix B(A.DIM);
		int i, j, k;

		for(i=0;i<DIM;i++)
			for(j=0;j<DIM;j++)
			{
				B.m[i][j] = 0;

				for(k=0;k<DIM;k++)
					B.m[i][j] = B.m[i][j] + m[i][k]*A.m[k][j];
			}

		return B;
	}

	void print()
	{
		int i, j;
		for(i=0;i<DIM;i++)
		{
			for(j=0;j<DIM;j++)
				printf("%u\t",m[i][j]);
			printf("\n");
		}
	}
};

Matrix BigMatrixExpo(Matrix &A, int n)
{
	Matrix B = A;
	Matrix C(A.DIM);

	int i,j;

	for(i=0;i<C.DIM;i++) 
		for(j=0;j<C.DIM;j++)
			C.m[i][j] = i==j ;

	while(n)
	{
		if(n&1)
		{
			C = C*B;
		}

		B = B*B;
		n>>=1;
	}

	return C;
}

//X^1 + X^2 + ... + X^n
Matrix seriessum(Matrix &X, LL n)
{
	if(n==1)
	{
		return X;
	}

	if(n%2)
	{
		Matrix Y = seriessum(X, n-1);
		Y = Y*X;
		Y = X + Y;

		return Y;
	}

	Matrix Y, Z;

	Y = BigMatrixExpo(X, n/2);
	Z = seriessum(X, n/2);
	Y = Y*Z;
	Y = Z + Y;

	return Y;
}
