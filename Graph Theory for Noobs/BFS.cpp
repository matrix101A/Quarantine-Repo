//in this code we would find the single source shortest path in a graph using BFS

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
int dis[1000001];//array to store distance of a node
vi ad[1000001]; //adjacency list of graph
void  bfs(int n)
{
         queue <int> q;
         q.push(n);
         int curr;
         dis[1]=0;
         while(!q.empty())
      {
        curr=q.front();
        q.pop();
         vis[curr]=1;
         for(int child : ad[curr])
         {
                  if(vis[child]==0)
                   {
                     q.push(child);
                     dis[child]=dis[curr]+1;
                   }
         }

       }

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
          bfs(1);  //running bfs fromw source node
          REP(i,n)cout<<dis[i]<<" ";

}
