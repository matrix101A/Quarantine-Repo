// calculating a^n of a matrix using concept of binary exponentiation !
#include <bits/stdc++.h>
using namespace std;
long a[51][51];
void matprint(long A[][51],long dim)
{
  for(int i=1;i<=dim;i++)
  {
    for(int j=1;j<=dim;j++)
    cout<<A[i][j]<<" ";
    cout<<"\n";
  }
}
void mul(long A[][51],long B[][51],int dim)
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
 void matpow(long A[][51],int dim ,int n)
{
  long res[51][51];
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
    int dim,n;
    cin>>dim>>n;
    for(int i=1;i<=dim;i++)
    {
      for(int j=1;j<=dim;j++)
      cin>>a[i][j];
    }
    matpow(a,dim,n);
    matprint(a,dim);
  }
}
