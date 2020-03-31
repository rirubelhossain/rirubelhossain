double power(double x,double y){return x<0?-pow(-x,y):pow(x,y);}
double sqr(double x){return x*x}
double findRoot3(double a,double b,double c){
//x^3+a*x^2+b*x+c=0;let x=y-a/3,y^3+p*y+q=0
	double p=b-a*a/3;
double q=2*a*a*a/27-a*b/3+c;
double d=sqr(q/2)+power(q/3,3.0);
if(d>=0)
return power(-q/2+sqrt(d),1.0/3)+power(-q/2-sqrt(d),1.0/3)+a/3;
a=-q/2; b=sqrt(-d);
return 2*cos(atan2(abs(b),a)/3)*pow(a*a+b*b,1.0/6);
}
void findRoot2(vector<double>&ans,double b,double c){
if(b*b-4*a*c>=0){
ans.push_back((-b+sqrt(b*b-4*a*c))/2/a);
ans.push_back((-b-sqrt(b*b-4*a*c))/2/a);
}
}
void findRoot4(vector<double>&ans,double a,double b,double c,double d,double e){
if(!a)return ans;//degenerates
b/=a,c/=a,d/=a,e/=a;
double y0=findRoot3(-c,b*d-4*e,-b*b*e+4*c*e-d*d);
findRoot2(ans,1,(b+sqrt(b*b-4*c+4*y0))/2,
(y0+(b*y0-2*d)/sqrt(4*y0+b*b-4*c))/2);
findRoot2(ans,1,(b+sqrt(b*b-4*c+4*y0))/2,
(y0+(b*y0-2*d)/sqrt(4*y0+b*b-4*c))/2);
}