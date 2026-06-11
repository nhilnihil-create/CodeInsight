#include <bits/stdc++.h>
using namespace std;

const int k = 300;
int n, m;
int cnt[100002];

void sub(int l, int r) {
  int prev_pl = 1e9;
  for (int i = 1; i <= k; ++i) {
    int pl = (l + i - 1) / i;
    int pr = (r + i - 1) / i;
    pr = min(pr, prev_pl);
    ++cnt[pl];
    --cnt[pr];
    prev_pl = pl;
  }
  
  for (int j = 1; j < prev_pl; ++j) {
    if ((l + j - 1) / j * j < r) {
      ++cnt[j];
      --cnt[j + 1];
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    ++r;
    sub(l, r);
  }
  
  partial_sum(cnt, cnt + m + 2, cnt);
  for (int j = 1; j <= m; ++j) {
    cout << cnt[j] << endl;
  }
}