//This code can check if a no is prime or nor in log n time .
#include <bits/stdc++.h>
using namespace std;
bool test(int a)
{

  for(int i=2;i*i<=a;i++)
  {
    if(a%i==0)
    return false;
  }
  return true;
}
int main()
{
  int a;
  cin>>a;
  if(test(a))
  cout<<"Prime";
  else
  cout<<"Composite";
}
