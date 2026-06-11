#include<bits/stdc++.h>
#define int long long
using namespace std;
signed power(int x, int n)
{
 if(n==0)
  return 1;
 else if(n%2==0)
  return pow((x*x),n/2);
 else
  return (x*pow((x*x),n/2));
}

signed main()
{
 int n,k;
 cin>>n>>k;
 cout<<k*power(k-1,n-1);
 return 0;
}