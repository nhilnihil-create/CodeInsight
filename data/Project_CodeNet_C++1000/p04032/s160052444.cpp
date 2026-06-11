#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, sum[N];
pair<int, int> pmin[N];
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  n = (int) s.size();
  for (int ch = 0; ch < 26; ch++) {
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] - 'a' == ch) {
        sum[i] = sum[i - 1] + 1;
      } else {
        sum[i] = sum[i - 1] - 1;
      }
      pmin[i] = min(pmin[i - 1], {sum[i], i});
    }
    for (int i = 2; i <= n; i++) {
      if (sum[i] - pmin[i - 2].first > 0) {
        cout << pmin[i - 2].second + 1 << " " << i << "\n";
        return 0;
      }
    }
  }
  cout << "-1 -1\n";
}
