#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


void solve(){

    string a;
    cin >> a;
    ll mp[30];
    rep(i,30){
        mp[i]=0;
    }
    rep(i,a.size()){
        mp[a[i]-'a']++;
    }

    ll n = a.size();
    ll ans = n*(n-1)/2+1;
    rep(i,30){
        ll t = mp[i];
        ans -= (t*(t-1)/2);
    }

    cout << ans << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
