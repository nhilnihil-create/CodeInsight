#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
  ll n,k;
  cin >> n >> k;
  ll a[n];
  rep(i,n) cin >> a[i];
    ll ans=1e18;
  rep(bit,1<<n){
    if(__builtin_popcount(bit)<k || bit%2==0)continue;
    vector<ll> s;
    rep(i,n) {
      if(bit>>i&1) s.push_back(i);
    }
    ll l = 0,total = 0;
    s.push_back(n);
    rep(j,s.size()-1){
        l = max(l+1,*max_element(a+s[j],a+s[j+1]));
        total += l - a[s[j]];
    }
    ans = min(ans,total);
  }
  cout << ans << endl;
}
