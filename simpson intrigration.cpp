Double a, b ;  / / input 
const  int N = 1000 * 1000 ,  / / number of steps (already multiplied by 2) 
Double s =  0 ; 
Double H =  ( b - a )  / N ; 
for  ( int I = 0 ; I <= N ;  + + I )  { 
	Double x = a + H * I ;
	s + = F ( x )  *  ( ( I == 0 | | I == N )  ? 1 :  ( ( I & 1 ) = = 0 )  ? 2 : 4 ) ; 
}
s * = H /  3 ;