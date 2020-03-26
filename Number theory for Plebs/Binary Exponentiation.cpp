
# include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,n;
  cin>>a>>n;
  int res=1;
  while(n)
{
     if(n%2==0)
     {
      n/=2;
      a*=a;
    }
     else
    {
     n=n-1;
     res*=a;
    }
}
cout<<res;
}
    
