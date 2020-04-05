// problem statement : https://www.codechef.com/problems/GCDQ
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
using namespace std;
int pre[100001];
int suff[100001];
int gcd(int a,int b)
{
         if(b==0) return a;
         else return gcd(b,a%b);
}
int main()
{
         int t;
         cin>>t;
         while(t--)
         {
                  int m,n;
                  cin>>m>>n;
                  int ar[m+1];
                  int k;
                  REP(i,m)
                  {

                          cin>>ar[i];
                  }
                  pre[0]=0;
                  suff[0]=0;
                  REP(i,m)
                  {
                           pre[i]=gcd(ar[i],pre[i-1]);
                           suff[i]=gcd(ar[m-i+1],suff[i-1]);
                  }

                  while(n--)
                  {
                           int l,r;
                           cin>>l>>r;
                           cout<<gcd(pre[l-1],suff[m-r])<<"\n";
                  }
         }
}
