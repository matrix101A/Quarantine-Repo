//A sieve contains all time prime numbers till a given number.
#include <bits/stdc++.h>
using namespace std;
bool prime[10000001];
void sieve()
{  int max=10000001;
  for(int i=1;i<=10000001;i++)prime[i]=true;
  prime[1]=prime[0]=false;
  for(int i=2;i*i<=max;i++)
  {
    if(prime[i])
    for(int j=i*i;j<=max;j+=i)
    prime[j]=0;
  }

}
int main()
{
  int a;
  cin>>a;
  sieve();
  for(int i=3;i<=a;i++)
  if(prime[i])
  cout<<i<<" ";// printng all prime no till a
}
