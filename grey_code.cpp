for(i=0;i<(1<<n);i++)
	grey_code[i]=i^(i>>1);

int g (int n) 
{
	return n ^ (n>> 1); 
}

int rev_g (int g)
{
  int n = 0; 
  for (; g; g>> = 1)
	  n ^ = g; 
  return n; 
} 
