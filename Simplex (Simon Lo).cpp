// Simon Lo's
// Simplex algorithm on augmented matrix a of dimension (m+1)x(n+1)
// returns 1 if feasible, 0 if not feasible, -1 if unbounded
// returns solution in b[] in original var order, max(f) in ret
// form: maximize sum_j(a_mj*x_j)-a_mn s.t. sum_j(a_ij*x_j)<=a_in
// in standard form.
// To convert into standard form:
// 1. if exists equality constraint, then replace by both >= and <=
// 2. if variable x doesn't have nonnegativity constraint, then replace by
// difference of 2 variables like x1-x2, where x1>=0, x2>=0
// 3. for a>=b constraints, convert to -a<=-b
// note: watch out for -0.0 in the solution, algorithm may cycle
// eps = 1e-7 may give wrong answer, 1e-10 is better

#define maxm 30
#define maxn 30
double inf = 1e100;
double eps = 1e-10;

void pivot(int m, int n, double a[maxm][maxn], int B[maxm], int N[maxn], int r, int c) {
	int i, j;
	swap(N[c], B[r]);
	a[r][c]=1/a[r][c];
	for (j=0; j<=n; j++)if (j!=c) a[r][j]*=a[r][c];
	for (i=0; i<=m; i++)if (i!=r) {
		for (j=0; j<=n; j++)if (j!=c)
			a[i][j]-=a[i][c]*a[r][j];
		a[i][c] = -a[i][c]*a[r][c];
	}
}
int feasible(int m, int n, double a[maxm][maxn], int B[maxm], int N[maxn]) {
	int r, c, i; double p, v;
	while (1) {
		for (p=inf, i=0; i<m; i++) if (a[i][n]<p) p=a[r=i][n];
		if (p>-eps) return 1;
		for (p=0, i=0; i<n; i++) if (a[r][i]<p) p=a[r][c=i];
		if (p>-eps) return 0;
		p = a[r][n]/a[r][c];
		for (i=r+1; i<m; i++) if (a[i][c]>eps) {
			v = a[i][n]/a[i][c];
			if (v<p) r=i, p=v;
		}
		pivot(m, n, a, B, N, r, c);
	}
}
int simplex(int m, int n, double a[maxm][maxn], double b[maxn], double& ret) {
	int B[maxm], N[maxn], r, c, i; double p, v;
	for (i=0; i<n; i++) N[i]=i;
	for (i=0; i<m; i++) B[i]=n+i;
	if (!feasible(m, n, a, B, N)) return 0;
	while (1) {
		for (p=0, i=0; i<n; i++) if (a[m][i]>p)
			p=a[m][c=i];
		if (p<eps) {
			for (i=0; i<n; i++) if (N[i]<n)
				b[N[i]]=0;
			for (i=0; i<m; i++) if (B[i]<n)
				b[B[i]]=a[i][n];
			ret = -a[m][n];
			return 1;
		}
		for (p=inf, i=0; i<m; i++) if (a[i][c]>eps) {
			v = a[i][n]/a[i][c];
			if (v<p) p=v, r=i;
		}
		if (p==inf) return -1;
		pivot(m, n, a, B, N, r, c);
	}
}
