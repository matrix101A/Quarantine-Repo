//This code can compute the minimum distance between two nodes in a tree in log n time
// this uses concept of finding the least common ancestor of two nodes using path compression
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
vi ad[1001]; //adjacency list of tree
int lvl[1001];//storing level of each node
int par[1001][11];//storing 2^i th parent of each node to implement path compression
void dfs(int n,int l,int p)//running dfs to set the level and parent node .
{
         par[n][0]=p;

         lvl[n]=l;
         for(int child : ad[n])
         {
                  if(child!=p)
                  dfs (child,l+1,n);
         }

}
int lca(int a,int b) // function to return least common ancestor
{
  if(lvl[a]-lvl[b]<0)
  {
    int temp=a;
    a=b;
    b=temp;
  }
  int dis=lvl[a]-lvl[b];
  while(dis--) a=par[a][0];
  if(a==b) return a;
  else
  {
           for(int i=10;i>=0;i--)
           {
                    if(par[a][i]!=-1&&par[a][i]!=par[b][i])
                    {
                             a=par[a][i];
                             b=par[b][i];
                    }
           }
  }
  return par[a][0];
}
int main()
{
          int n,a,b,dis=0;

          cin>>n;
          REP(i,n-1)
          {
                  int a,b;
                  cin>>a>>b;
                  ad[a].pb(b);
                  ad[b].pb(a);
          }
          REP(i,n)
         {
           for(int j=0;j<=10;j++)
           par[i][j]=-1;
         }

          dfs(1,0,-1);
          for(int i=1;i<=10;i++)
          {
            for(int j=1;j<=n;j++)
            {
              if(par[j][i-1]!=-1)
              par[j][i]=par[par[j][i-1]][i-1];
            }
          }
          cin>>a>>b;

          dis=lvl[a]+lvl[b]-2*lvl[lca(a,b)];//calculating disting using the relation .
          cout <<dis;


}
