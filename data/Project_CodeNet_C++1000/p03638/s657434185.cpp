#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;
// const int INF=1010101010;
using Graph = vector<vector<int>>;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  string s[h][w];
  int now = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[now] == 0) now++;
      s[i][j] = to_string(now + 1);
      a[now]--;
    }
    i++;
    if (i >= h) break;
    for (int j = w - 1; j >= 0; j--) {
      if (a[now] == 0) now++;
      s[i][j] = to_string(now + 1);
      a[now]--;
    }
  }
  rep(i, h) {
    rep(j, w) { cout << s[i][j] << " "; }
    cout << endl;
  }
}