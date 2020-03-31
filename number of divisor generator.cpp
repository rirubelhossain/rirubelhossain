const int MAX = 1000100;int n;bool num[1100];//sqrt(MAX)
int prime[1100], total;__int64 f[MAX], inc[MAX];
void cal_prime() {int i,j;memset(num, false, sizeof(num));total = 0;
	for(i=2;i<1100;i++) {
		if(!num[i]) {prime[total ++] = i;j = i+i;
			while(j < 1100) {num[j] = true;j += i;}}}}
void cal_farey() {int i,j,k;inc[1] = 1;
	for(i=2;i<MAX;i++) {
		for(j=0;j<total;j++) {
			if(i%prime[j] == 0) {k = i / prime[j];
				if(k%prime[j] == 0) inc[i] = inc[k] * prime[j];
				else inc[i] = inc[k] * (prime[j] -1);
				break;}}
		if(j == total) inc[i] = i -1;}
	f[1] = 0;
	for(i=2;i<MAX;i++) f[i] = f[i-1] + inc[i];}

int main() {cal_prime();cal_farey();
	while(scanf("%d", &n), n) {printf("%I64d\n", f[n]);}}
