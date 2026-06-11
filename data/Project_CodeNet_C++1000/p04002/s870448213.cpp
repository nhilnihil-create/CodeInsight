#include<bits/stdc++.h>

using namespace std;

static const int INF = 1e9 + 7;

using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using ull = unsigned long long;



void hawawa()
{
  long long h, w, n;
  cin >> h >> w >> n;
  set<pair<int, int> > s;
  unsigned long long ans[10] = {(h - 2) * (w - 2)};
  while (n--) {
    int a, b;
    cin >> a >> b;
    auto status = make_pair(a, b);
    s.insert(status);
    short cnt = 0;
    for (int i = a - 2; i <= a && i + 2 <= h; i++) {
      if (i <= 0) continue;
      for (int j = b - 2; j <= b && j + 2 <= w; j++) {
        if (j <= 0) continue;
        int cnt = 0;
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            cnt += s.count(make_pair(i + k, j + l));
          }
        }
        if (cnt) {
          ans[cnt - 1]--;
        }
        ans[cnt]++;
      }
    }
  }
  for (auto&& i : ans) {
    cout << i << "\n";
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  hawawa();
}