typedef vector< vector<double> > VVI;

VVI F(4, vector<double> (4,0));
VVI R(4, vector<double> (4,0));
VVI L(4, vector<double> (4,0));
VVI U(4, vector<double> (4,0));
VVI D(4, vector<double> (4,0));
VVI I(4, vector<double> (4,0));

VVI multiply(VVI A, VVI B)
{
	VVI C(SZ(A), vector<double> (SZ(B[0]),0));
	int i, j, k;
	for(i=0;i<SZ(A);i++)
		for(j=0;j<SZ(B[0]);j++)
		{
			C[i][j] = 0;
			for(k=0;k<SZ(A[0]);k++)
				C[i][j] += A[i][k]*B[k][j];
		}

	return C;
}

VVI power(VVI A, int n)
{
	VVI ans = I;
	int i;
	for(i=1;i<=n;i++)
		ans = multiply(A,ans);
	return ans;
}

void print(VVI A)
{
	for(int i = 0;i<SZ(A);i++)
	{
		for(int j = 0; j < SZ(A[0]);j++)
		{
			printf("%3lf ",A[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");
}

/*
		vector< vector<double> > B(4, vector<double> (4,0));
		VVI A;

		B[0][0]=0; B[0][1]=0; B[0][2]=1; B[0][3]=0;
		B[1][0]=1; B[1][1]=0; B[1][2]=0; B[1][3]=0;
		B[2][0]=0; B[2][1]=1; B[2][2]=0; B[2][3]=0;
		B[3][0]=0; B[3][1]=0; B[3][2]=0; B[3][3]=0;

*/



define MAXN 100
#define fabs(x) ((x)>0?(x):-(x))
#define zero(x) (fabs(x)<1e-10)
struct mat{
int n,m;
double data[MAXN][MAXN];
};
int mul(mat& c,const mat& a,const mat& b){
int i,j,k;
if (a.m!=b.n)
return 0;
c.n=a.n,c.m=b.m;
for (i=0;i<c.n;i++)
for (j=0;j<c.m;j++)
for (c.data[i][j]=k=0;k<a.m;k++)
c.data[i][j]+=a.data[i][k]*b.data[k][j];
return 1;
}
int inv(mat& a){
int i,j,k,is[MAXN],js[MAXN];
double t;
if (a.n!=a.m)
return 0;
for (k=0;k<a.n;k++){
for (t=0,i=k;i<a.n;i++)
for (j=k;j<a.n;j++)
if (fabs(a.data[i][j])>t)
t=fabs(a.data[is[k]=i][js[k]=j]);
if (zero(t))
return 0;
if (is[k]!=k)
for (j=0;j<a.n;j++)
t=a.data[k][j],a.data[k][j]=a.data[is[k]][j],a.data[is[k]][j]=t;
if (js[k]!=k)
for (i=0;i<a.n;i++)
t=a.data[i][k],a.data[i][k]=a.data[i][js[k]],a.data[i][js[k]]=t;
a.data[k][k]=1/a.data[k][k];
for (j=0;j<a.n;j++)
if (j!=k)
a.data[k][j]*=a.data[k][k];
for (i=0;i<a.n;i++)
if (i!=k)
for (j=0;j<a.n;j++)
if (j!=k)
a.data[i][j]-=a.data[i][k]*a.data[k][j];
for (i=0;i<a.n;i++)
if (i!=k)
a.data[i][k]*=-a.data[k][k];
}
for (k=a.n-1;k>=0;k--){
for (j=0;j<a.n;j++)
if (js[k]!=k)
t=a.data[k][j],a.data[k][j]=a.data[js[k]][j],a.data[js[k]][j]=t;
for (i=0;i<a.n;i++)
if (is[k]!=k)
t=a.data[i][k],a.data[i][k]=a.data[i][is[k]],a.data[i][is[k]]=t;
}
return 1;
}
double det(const mat& a){
int i,j,k,sign=0;
double b[MAXN][MAXN],ret=1,t;
if (a.n!=a.m)
return 0;
for (i=0;i<a.n;i++)
for (j=0;j<a.m;j++)
b[i][j]=a.data[i][j];
for (i=0;i<a.n;i++){
if (zero(b[i][i])){
for (j=i+1;j<a.n;j++)
if (!zero(b[j][i]))
break;
if (j==a.n)
return 0;
for (k=i;k<a.n;k++)
t=b[i][k],b[i][k]=b[j][k],b[j][k]=t;
sign++;
}
ret*=b[i][i];
for (k=i+1;k<a.n;k++)
b[i][k]/=b[i][i];
for (j=i+1;j<a.n;j++)
for (k=i+1;k<a.n;k++)
b[j][k]-=b[j][i]*b[i][k];
}
if (sign&1)
ret=-ret;
return ret;
}
