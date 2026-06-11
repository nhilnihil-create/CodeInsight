#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	ll n;
  cin>>n;
  ll sum=0;
  for  (ll i=1;i<=n;i++){
    sum+=i;
  }
  cout<<sum<<"\n";
	return 0;
}
