/*In usual n^3 determinant finding,  In each iteration we choose a pivot element, and use that to make all element below it zero.
We apply following identity

r'j=rj-ri*x
with x=a[j][i]/a[i][i]

Now, to avoid division, we can rather use following identity,

r'i=x0*ri+y0*rj
r'j=x1*ri+y1*rj

which will be valid if determinant of following matrix is 1.

x0  y0
x1  y1

Now if we can find x0,y0 such that x1=-a[j][i] and y1=a[i][i]. then we are done.
That is we need to find x0,y0 such that
x0*a[i][i]+y0*a[i][j]=1
This is where extended gcd can help.
*/
//============================================================================
// Name        : timus1627.cpp
// Author      : Tanaeem
// Version     :
// Copyright   : 
// Description : 
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

#define MOD 1000000000

long long ex, ey;
long long egcd(long long a, long long b)
  {
    if (b==0)
      {
        ex=1;
        ey=0;
        return a;
      }
    long long dd=egcd(b, a%b);
    long long tx=ey;
    ey=ex-(a/b)*ey;
    ex=tx;
    return dd;
  }

long long A[110][110];
int n;

long long det()
  {
    long long ans=1;
    for (int i = 0; i < n; ++i)
      {
        int j;
        long long t;
        for (j = i; j < n; ++j)
          {
            if (A[j][i]!=0)
              break;
          }
        if (j==n)
          return 0;
        if (i!=j)
          {
            ans*=-1;
            for (int k = i; k < n; ++k)
              {
                t=A[i][k];
                A[i][k]=A[j][k];
                A[j][k]=t;
              }
          }
        for (j = i+1; j < n; ++j)
          {
            if (A[j][i]==0)
              continue;
            long long d=egcd(A[i][i], A[j][i]);
            long long ax=-A[j][i]/d;
            long long ay=A[i][i]/d;
            for (int k = i; k < n; ++k)
              {
                t=A[i][k]*ex+A[j][k]*ey;
                t%=MOD;
                if (t<0)
                  t+=MOD;
                A[j][k]=A[i][k]*ax+A[j][k]*ay;
                A[j][k]%=MOD;
                if (A[j][k]<0)
                  A[j][k]+=MOD;
                A[i][k]=t;
              }
          }
        ans*=A[i][i];
        ans%=MOD;
      }
    ans%=MOD;
    return ans;
  }

char inp[20][20];
int num[20][20];
int dx[]=
  { 0, 0, 1, -1 };
int dy[]=
  { 1, -1, 0, 0 };
int main()
  {
    int r, c;
    scanf("%d%d", &r, &c);

    for (int i = 0; i < r; ++i)
      {
        scanf("%s", inp[i]);
      }
    n=0;
    for (int i = 0; i < r; ++i)
      {
        for (int j = 0; j < c; ++j)
          {
            if (inp[i][j]!='*')
              num[i][j]=n++;
          }
      }
    for (int i = 0; i < r; ++i)
      {
        for (int j = 0; j < c; ++j)
          {
            for (int k = 0; k < 4; ++k)
              {
                int ni=i+dx[k];
                int nj=j+dy[k];
                if (ni<0 || ni>=r || nj<0 || nj>=c)
                  continue;
                if (inp[i][j]=='.' && inp[ni][nj]=='.')
                  {
                    A[num[i][j]][num[ni][nj]]--;
                    A[num[i][j]][num[i][j]]++;
                  }
              }
          }
      }

    for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
          {
            if (A[i][j]<0)
              A[i][j]+=MOD;
          }
      }
    n--;

    long long ans=det();
    if(ans<0)
      ans+=MOD;
    printf("%lld\n", ans);
    return 0;
  }
