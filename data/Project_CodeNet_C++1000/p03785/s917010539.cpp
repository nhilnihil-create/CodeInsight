#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl;
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() {
  ll n, c, k; cin >> n >> c >> k;
  Vl t(n);
  rep(i, 0, n) cin >> t[i];
  sort(ALL(t));
  ll ans = 1, cnt = 1, T = t[0];
  rep(i, 1, n){
    if(cnt >= c || t[i] > T+k){
      ans++;
      T = t[i];
      cnt = 1;
    }else{
      cnt++;
    }
  }
  cout << ans << endl;

  return 0;
}