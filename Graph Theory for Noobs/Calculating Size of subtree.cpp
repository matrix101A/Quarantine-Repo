//calculating size of a subtree using DFS algo.
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
vi vis(1000001);
int size[1000001];//array to store size of subtree
vi ad[1000001]; //adjacency list of graph
int  dfs(int n)
{
         vis[n]=1;
         int cnt=1;
         for(int child : ad[n])
         {
                  if(vis[child]==0)
                cnt += dfs (child);
         }
         size[n]=cnt;
         return cnt;

}
int main()
{
          int n,m;  //no of nodes and edges
          cin>>n>>m;

          REP( i,m)
          {
                  int a,b;
                  cin>>a>>b;
                  ad[a].pb(b);
                  ad[b].pb(a);
          }
          REP(i,n)vis[i]=0;
          dfs(1);
          REP(i,n)cout<<size[i]<<" ";

}
