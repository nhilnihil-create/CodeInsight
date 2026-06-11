// clang-format off
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
#define rrep(i,n) for(ll i=n-1; i>=0; --i)
#define rrep1(i,n) for(ll i=n; i>0; --i)
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define SORT_DESC(x) sort(all(x), greater<>())
#define pb push_back
#define mp make_pair
#define coutl cout<<fixed<<setprecision(10)
#define ANS(ans) cout<<ans<<endl;
#define INF 1e9;
#define LINF 1e18;
template<class T>bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if (b<a){a=b;return 1;}return 0;}
// clang-format on

void solve(long long H, long long W, long long N, std::vector<long long> a) {
  vector<ll> c;
  rep(i, a.size()) rep(j, a[i]) c.pb(i + 1);
  rep(h, H) {
    if (h % 2 == 0) {
      rep(w, W) {
        cout << c[h * W + w];
        if (w < W - 1)
          cout << " ";
      }
      cout << endl;
    } else {
      string l;
      rrep(w, W) {
        l = to_string(c[h * W + (W - w - 1)]) + l;
        if (w != 0)
          l = " " + l;
      }
      cout << l << endl;
    }
  }
}

// clang-format off
int main() {
  long long H;
  scanf("%lld",&H);
  long long W;
  scanf("%lld",&W);
  long long N;
  scanf("%lld",&N);
  std::vector<long long> a(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&a[i]);
  }
  solve(H, W, N, std::move(a));
  return 0;
}
