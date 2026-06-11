#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	ll n,k,x,y;
  cin>>n>>k>>x>>y;
  ll sum=0;
  
  if (n>=k){
    sum+=k*x;
    sum+=(n-k)*y;
  }
  else sum+=n*x;
  cout<<sum<<"\n";
  
	return 0;
}
