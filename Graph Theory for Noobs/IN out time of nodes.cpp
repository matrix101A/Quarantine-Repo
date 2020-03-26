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
vi vis(1000001);//visited array
int  in[1000001];//stores in time of node
int out[1000001];// stores out time of node
vi ad[1000001]; //adjacency list of graph
int c=0;
void dfs(int n)
{
         vis[n]=1;
         in[n]=c++;
         for(int child : ad[n])
        {
                  if(vis[child]==0)
                   dfs (child);
        }
        out[n]=c++;

}
int main()
{
          int n,m;  //no of nodes and edges
          int k ;//beginig node for dfs
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
          cout<<in[1]<<" "<<out[1];
}
