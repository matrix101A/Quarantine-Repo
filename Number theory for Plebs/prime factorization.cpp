// prime factorization in sqrt n complexity
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  for(int i=2;i*i<=n;i++)
  { int c=0;
    if(n%i==0)
    {
      while(n%i==0)
      {
        n/=i;
        c++;
      }
      cout<<i<<"^"<<c<<" ";
    }
  }
  if(n>0)
  cout<<n<<"^"<<1;
}
