/*
ax + by = g

general soln:
x = x + kb
y = y - ka

for any k

FOR:
ax + by = D

general soln:
x = x + kb/g
y = y - ka/g

for any k
*/
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