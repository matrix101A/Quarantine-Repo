// problem statement :https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/description/
// concepts : seive ,cumilative sum

#include <bits/stdc++.h>
using namespace std;
int prime[1000001];
int no[1000001];
int cum[1000001];
void sieve()
{
	int max=1000001;
	for(int i=2;i<max;i++)
	prime[i]=1;
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i*i<=max;i++)
	{
		if(prime[i]==1)
		{for(int j=i*i;j<=max;j+=i)
	    prime[j]=0;
		}
	}
	no[0]=no[1]=0;
	int c=0;
	for(int i=2;i<=max;i++)
	{
		if(prime[i]==1)
		c++;

		if(prime[c]==1)
		no[i]=no[i-1]+1;
		else no[i]=no[i-1];

	}

}
int main()
{
	int t;
	cin>>t;
	sieve();
	while(t--)
	{	int c=0;
		int l,u;
		cin>>l>>u;

		cout<<no[u]-no[l-1]<<"\n";
	}
}
