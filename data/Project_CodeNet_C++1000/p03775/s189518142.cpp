#include<iostream>
using namespace std;
using ll = long long;

int digit(ll x) {
  int res=1;
  while(x/10!=0) {
    res++;
    x/=10;
  }
  return res;
}

int main() {
  ll N;
  int ans=10;
  cin>>N;
  for (ll i=1;i*i<=N;i++) {
    if (N%i == 0) {
      ans = min(ans, digit(N/i));
    }
  }
  cout<<ans<<endl;
  return 0;
}
