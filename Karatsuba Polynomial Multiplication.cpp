#define SZ(X) (int)X.size()

typedef vector<int> VI;

VI Karatsuba_Polynomial_Multiplication(VI &X, VI &Y)
{
	int i, j;

	if(SZ(Y) <= 100)
	{
		VI Z(SZ(X) + SZ(Y), 0);
		for(i = SZ(X) - 1; i >= 0; i--)
			for(j = SZ(Y) - 1; j >= 0; j--)
				Z[i + j] += X[i]*Y[j];

		return Z;
	}

	int sz = SZ(X), lim;
	VI LX, RX, LY, RY, Z(2*sz, 0), L, R, M;
		
	lim = sz/2;

	for(i = 0; i < sz; i++)
		if(i < lim) LX.push_back( X[i] );
		else       	RX.push_back( X[i] );
	
	for(i = 0; i < sz; i++)
		if(i < lim) LY.push_back( Y[i] );
		else       	RY.push_back( Y[i] );

	L = Karatsuba_Polynomial_Multiplication(LX, LY);
	R = Karatsuba_Polynomial_Multiplication(RX, RY);

	for(i = 0; i < lim; i++) LX[i] += RX[i];
	for(i = 0; i < lim; i++) LY[i] += RY[i];

	M = Karatsuba_Polynomial_Multiplication(LX, LY);
	
	for(i = 0; i < sz; i++)
		M[i] = M[i] - L[i] - R[i];

	for(i = 0; i < sz; i++)
	{
		Z[i] += L[i];
		Z[i + lim] += M[i];
		Z[i + sz] += R[i];
	}

	return Z;
}
