#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pii> ab(N);
  vector<pii> cd(M);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    ab[i].first = a;
    ab[i].second = b;
  }
  rep(i, M) {
    int c, d;
    cin >> c >> d;
    cd[i].first = c;
    cd[i].second = d;
  }

  int curr;
  int ans;
  rep(i, N) {
    int a, b;
    tie(a, b) = ab[i];
    curr = 1000000000;
    rep(j, M) {
      int c, d;
      tie(c, d) = cd[j];
      int dist = abs(c-a)+abs(d-b);
      if (dist < curr) {
        ans = j+1;
        curr = dist;
      }
    }
    cout << ans << endl;
  }
}
