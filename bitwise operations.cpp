/*
Remove last 1
11011101010000 2 = n 
11011101001111 2 = n - 1 
11011101000000 2 = n & (n - 1)
*/

n = n & (n-1)

//count number of 1 bits
int count ( long n) {
int count = 0;
if (n)
do count + +; while (n & = n - 1);
return number;
}

//Parity of number of 1 bits in O(1)
int parity ( long n) {
n = ((0xFFFF0000 & n) >> 16) ^ (n & 0xFFFF);
n = ((0xFF00 & n) >> 8) ^ (n & 0xFF);
n = ((0xF0 & n) >> 4) ^ (n & 0xF);
n = ((12 & n) >> 2) ^ (n & 3);
n = ((2 & n) >> 1) ^ (n & 1);
return n;
}

//Determine last 1 bit
x = n ^ (n&(n-1))

//If n is power of 2
if( (n&(n-1))==0 ) return true;
else return false;

