//problem satatement :
#include<bits/stdc++.h>
using namespace std;
# define mod 1000000007
int main()
{
         int t;
         cin>>t;
         long dp[1000000001];
                  dp[1]=1;
                  dp[2]=2;
                  dp[3]=4;
                  for(int i=4;i<=100000000;i++)
                  dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%mod;
         while(t--)
         {
                  lli n;
                  cin>>n;
                  cout<<dp[n]<<endl;
         }

}
