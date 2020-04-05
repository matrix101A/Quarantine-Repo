//NOt your conventional fibonacci question
// use matrix exp. to reduce complexity to log(n);
//link -https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem
#include <bits/stdc++.h>
using namespace std;
long a[3][3];
long f[3][3];

void mul(long A[][3],long B[][3],int dim)
{
 long  res[dim+1][dim+1];
  for(int i=1;i<=dim;i++)
  {
    for(int j=1;j<=dim;j++)
     {res[i][j]=0;
     for(int k=1;k<=dim;k++) res[i][j]=(res[i][j]+(A[i][k]*B[k][j]))%(1000000007);}
  }

  for(int i=1;i<=dim;i++)
  {
    for(int j=1;j<=dim;j++)
     A[i][j]=res[i][j];
  }
}
 void matpow(long A[][3],int dim ,int n)
{
  long res[3][3];
  for(int i=1;i<=dim;i++)
  {
    for(int j=1;j<=dim;j++)
     if(i==j)
     res[i][i]=1;
     else
     res[i][j]=0;
  }

  while(n)
  {
    if(n%2==1)
    {
      n=n-1;
       mul(res,A,dim);
    }
    mul(A,A,dim);
    n/=2;
  }
  for(int i=1;i<=dim;i++)
    {
      for(int j=1;j<=dim;j++)
      a[i][j]=res[i][j];
    }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long dim=2,a1,b,n;
    cin>>a1>>b>>n;
    a[1][1]=0;a[1][2]=a[2][1]=a[2][2]=1;
    matpow(a,dim,n);
    f[1][1]=a1;f[1][2]=b;f[2][1]=f[2][2]=0;
    mul(f,a,4);
    cout<<f[1][1]<<"\n";
  }
}
