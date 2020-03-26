//Diameter of a tree is the farthest distance between two nodes
#include<bits/stdc++.h>
using namespace std;
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
vi dis(1000001); //stores distance of node
vi ad[1000001]; //adjacency list of graph
void dfs(int n,int c)
{
  vis[n]=1;
  dis[n]=c;
  for(int child : ad[n])
  {
    if(vis[child]==0)
    {
      dfs(child,c+1);
    }
  }
}
int main()
{
  int n,m;
  cin>>n>>m;
  REP(i,m)
  {
    int a,b;
    cin>>a>>b;
    ad[a].pb(b);
    ad[b].pb(a);
    vis[i]=0;
  }
  dfs(1,0);
  int max=-1,mn=1;
  REP(i,n)
  {
    if(dis[i]>max)
    {max=dis[i];
    mn=i;
    }
  }
  REP(i,n)vis[i]=0;
  dfs(mn,0);
  max=-1;
  REP(i,n)
  {
    if(dis[i]>max)
    max=dis[i];
  }
  cout<<max;
}
