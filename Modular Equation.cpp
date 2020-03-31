int extgcd(int a, int b, int & x, int & y){
if (b == 0) { x=1; y=0; return a; }
int d = extgcd(b, a % b, x, y);
int t = x; x = y; y = t - a / b * y;
return d;
}

//a * x = b (% n)
void modeq(int a, int b, int n) // ! n > 0
{
int e, i, d, x, y;
d = extgcd(a, n, x, y);
if (b % d > 0) printf("No answer!\n");
else {
e = (x * (b / d)) % n;
for (i = 0; i < d; i++) // !!! here x maybe < 0
printf("%d-th ans: %d\n", i+1, (e+i*(n/d))%n);
}
}