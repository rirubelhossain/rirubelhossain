// z % a1 == b1 // z % a2 == b2
// a1,a2 > 0, b1,b2 >= 0, a1 > b1, a2 > b2
// Return true if possible, false otherwise
bool chin_rem(int a1, int b1, int a2, int b2, int& a, int& b) 
{
	int X1, X2;
	int d = egcd(a1, a2, X1, X2);
	if ( (b1 % d) != (b2 % d) ) return false;
	a = a1 / d * a2;
	b = (X1*a1*(b2/d) + X2*a2*(b1/d) + (b1%d))%a;
	return true;
}


//
int extgcd(int a, int b, int & x, int & y){
if (b == 0) { x=1; y=0; return a; }
int d = extgcd(b, a % b, x, y);
int t = x; x = y; y = t - a / b * y;
return d;
}

int china(int b[], int w[], int k){
int i, d, x, y, m, a = 0, n = 1;
for (i = 0; i < k; i++) n *= w[i];
for (i = 0; i < k; i++) {
m = n / w[i];
d = extgcd(w[i], m, x, y);
a = (a + y * m * b[i]) % n;
}
if (a > 0) return a;
else return (a + n);
}