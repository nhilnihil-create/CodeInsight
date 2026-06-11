#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int a[100];
int cells[100][100]; // r * c

int main() {
  ll N, W;
  cin >> N >> W;

  vector<ll> w(N), v(N);
  rep0(i, N) cin >> w[i] >> v[i];

  vector<ll> v0, v1, v2, v3;
  
  rep0(i, N) {
    if (w[i] == w[0] + 0) v0.push_back(v[i]);
    else if (w[i] == w[0] + 1) v1.push_back(v[i]);
    else if (w[i] == w[0] + 2) v2.push_back(v[i]);
    else if (w[i] == w[0] + 3) v3.push_back(v[i]);
  }
  sort(v0.begin(), v0.end()); v0.push_back(0); reverse(v0.begin(), v0.end());
  sort(v1.begin(), v1.end()); v1.push_back(0); reverse(v1.begin(), v1.end());
  sort(v2.begin(), v2.end()); v2.push_back(0); reverse(v2.begin(), v2.end());
  sort(v3.begin(), v3.end()); v3.push_back(0); reverse(v3.begin(), v3.end());
  // SHOW(v0);SHOW(v1);SHOW(v2);SHOW(v3);

  ll temp;
  temp = 0; rep(i, 1, v0.size()) v0[i] += v0[i - 1];
  temp = 0; rep(i, 1, v1.size()) v1[i] += v1[i - 1];
  temp = 0; rep(i, 1, v2.size()) v2[i] += v2[i - 1];
  temp = 0; rep(i, 1, v3.size()) v3[i] += v3[i - 1];

  ll ans = 0;
  rep0(i0, v0.size()) {
    if (w[0] * i0 > W) break;
    ans = max(ans, v0[i0]);
    // cout << i0 << ":" << ans << BR;

    rep0(i1, v1.size()) {
      if (w[0] * i0 + (w[0] + 1) * i1 > W) break;
      ans = max(ans, v0[i0] + v1[i1]);
      // cout << i0 << SP << i1 << ":" << ans << BR;

      rep0(i2, v2.size()) {
        if (w[0] * i0 + (w[0] + 1) * i1 + (w[0] + 2) * i2 > W) break;
        ans = max(ans, v0[i0] + v1[i1] + v2[i2]);
        // cout << i0 << SP << i1 << SP << i2 << ":" << ans << BR;

        rep0(i3, v3.size()) {
          if (w[0] * i0 + (w[0] + 1) * i1 + (w[0] + 2) * i2 + (w[0] + 3) * i3 > W) break;
          ans = max(ans, v0[i0] + v1[i1] + v2[i2] + v3[i3]);
          // cout << i0 << SP << i1 << SP << i2 << SP << i3 << ":" << ans << BR;
        }
      }
    }
  }
  cout << ans;
  return 0;
}