//This code uses Disjoint set union to calculate minimum spanning tree of a graph.
# include <bits/stdc++.h>
using namespace std;
struct edge   //initializing structure
{
	int a;
	int b;
	int w;
};
edge ar[100000]; //array of structure
int parent[10001]; //array to store parent of the set
bool comp(edge a,edge b)  //comp function for sort()
{
    if(a.w < b.w)
	return true;
	else
	return false;
}
void merge (int a,int b)
{
	parent[a]=b;
}
int find(int a)  //function to find the parent
{
	if(parent[a]<0)
	return a;
    else
	return parent[a]=find(parent[a]);
}

int main()
{
	int n,m,a,b,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++) parent[i]=-1;

	for(int i=0;i<m;i++)
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
		w=0;
		sort(ar,ar+m,comp);
		for(int i=0;i<m;i++)
		{
			a=find(ar[i].a);
			b=find(ar[i].b);

			if(a!=b)
			{
			 w+=ar[i].w;
			 merge(a,b);
			}
		}
		cout<<w;

}
