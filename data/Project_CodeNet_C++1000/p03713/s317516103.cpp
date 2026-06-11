// https://atcoder.jp/contests/abc062/tasks/arc074_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DUMP(a, n) REP(_i, n) printf("%d%c", a[_i], _i + 1 == n ? '\n' : ' ')
#define DUMP2D(a, n, m) REP(_i, n) REP(_j, m) printf("%d%c", a[_i][_j], _j + 1 == m ? '\n' : ' '); puts("")

const int H_MAX = 1e5;
const int W_MAX = 1e5;
const ll INF = 1e12;

ll H, W;

void split(ll w, ll h, ll &s1, ll &s2) {
  ll s = w * h;
  if (s % 2 == 0) {
    s1 = s2 = s / 2;
  } else {
    s1 = (s + min(w, h)) / 2;
    s2 = s - s1;
  }
}

ll sd(ll s1, ll s2, ll s3) {
  ll ret = abs(s1 - s2);
  ret = max(ret, abs(s2 - s3));
  ret = max(ret, abs(s3 - s1));
  return ret;
}

void solve() {
  ll ans = INF;
  ll s1, s2, s3;
  FOR(w1, 1, W - 1) {
    s1 = w1 * H;
    split(W - w1, H, s2, s3);
    ans = min(ans, sd(s1, s2, s3));
  }
  FOR(h1, 1, H - 1) {
    ll s1 = W * h1;
    split(W, H - h1, s2, s3);
    ans = min(ans, sd(s1, s2, s3));
  }
  printf("%lld\n", ans);
}

void input() {
  scanf("%lld%lld", &H, &W);
}

int main() {
  input();
  solve();
  return 0;
}
