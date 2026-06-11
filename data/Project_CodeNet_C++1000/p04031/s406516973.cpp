#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char **argv)
{
	ll n;
  cin>>n;
  vector <ll> arr(n);
  for(ll i=0;i<n;i++) cin>>arr[i];
  ll ans=numeric_limits<int>::max();
  for(ll i=-100;i<=100;i++){
    ll sum=0;
    for(ll j=0;j<n;j++){
      sum+=pow((arr[j]-i),2);
    }
    if (sum<ans) {
      ans=sum;
    }
  }
  cout<<ans<<"\n";
	return 0;
}
