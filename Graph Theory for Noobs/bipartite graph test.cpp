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
vi col(1000001); //stores color of node
vi ad[1000001]; //adjacency list of graph
bool dfs(int n,int c)
{
         vis[n]=1;
         col[n]=c;
         for(int child : ad[n])
         {
                  if(vis[child]==0)
                   return dfs (child ,col[n]^1);
                  if(col[child]==col[n])
                  return false;
           }
           return true;

}
int main()
{
          int n,m;  //no of nodes and edges
          int k ;//beginig node for dfs
          cin>>n>>m;
          REP( i,n)
          {
                  int a,b;
                  cin>>a>>b;
                  ad[a].pb(b);
                  ad[b].pb(a);
          }
          REP(i,n)vis[i]=0,col[i]=0;
          cin >>k;
          if(dfs(1,0))
          cout<<"It is bipartite";
          else
          cout <<"It is not bipartite";
}
