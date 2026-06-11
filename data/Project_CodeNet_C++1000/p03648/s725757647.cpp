#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll k;
  cin >> k;
  vec ans(50);
  for(ll i=0;i<50;i++) {
    ans[i]=i+k/50;
  }
  k%=50;
  for(ll i=0;i<50;i++) {
    if(i<k) {
      ans[i]+=50-(k-1);
    }
    else {
      ans[i]-=k;
    }
  }
  cout << 50 << endl;
  for(ll i=0;i<50;i++) {
    if(i!=0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << endl;
}