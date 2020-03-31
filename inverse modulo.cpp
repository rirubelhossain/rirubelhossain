int egcd (int a, int b, int &x, int &y) 
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}

	int x1, y1;
	int d = egcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}

int invmod(int r,int m) //find r^-1 (mod m)
{
	int x, y; 
	int g = egcd (r, m, x, y); 
	if (g! = 1) return 0; //Impossible 
	else return x;
}
