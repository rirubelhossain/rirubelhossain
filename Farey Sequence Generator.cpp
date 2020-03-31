const int MAX = 8000000;int total;int n,k;int farey[2][MAX];
void make_farey_seq(int x1,int y1,int x2, int y2)
{  if(x1+x2 > n || y1+y2 > n) return;
	make_farey_seq(x1, y1,x1+x2, y1+y2);total ++;
	farey[0][total] = x1+x2;farey[1][total] = y1+y2;
	make_farey_seq(x1+x2, y1+y2,x2,y2);}
int main() {int t;scanf("%d %d", &n, &t);
	total = 1;farey[0][1] = 0;farey[1][1] = 1;make_farey_seq(0,1,1,1);
	farey[0][total+1] = 1;farey[1][total+1] = 1;total ++;
	while(t --) {scanf("%d", &k);
		if(k > total) puts("No Solution");
		else printf("%d/%d\n", farey[0][k], farey[1][k]);}}
