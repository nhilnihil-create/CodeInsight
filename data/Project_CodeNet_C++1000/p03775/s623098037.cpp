#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

ll f(ll x){
  string s = to_string(x);
  return sz(s);
}

int main(int argc, char const *argv[]) {
  ll n;
  cin >> n;
  ll ans = INF;
  for (ll i = 1; i <= sqrt(n); i++){
    if (n % i != 0) continue;
    ll j = n / i;
    ll tmp = max(f(i), f(j));
    chmin(ans, tmp);
    if (i == 1) i++;
  }
  cout << ans << endl;
  return 0;
}