#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> m >> n;
  vector<int> pos(m);
  for (int i = 0; i < m; i++) {
    cin >> pos[i];
    pos[i]--;
  }

  vector<long long> accu(n + 1), cnt(n + 1);
  long long all = 0;
  int l, r;

  for (int i = 0; i < m - 1; i++) {
    all += (pos[i + 1] - pos[i] + n) % n;
    l = pos[i];
    r = pos[i + 1];
    if (l < r) {
      cnt[l + 1]++;
      cnt[r]--;
      accu[r + 1] -= (r - l - 1);
    } else {
      // right part
      cnt[l + 1]++;
      // left part
      accu[0] += (n - l - 1);
      accu[r + 1] -= (n - (l - r) - 1);
      cnt[0]++;
      cnt[r]--;
    }
  }

  long long sum = 0, num = 0;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    sum += accu[i];
    num += cnt[i];
    a[i] = sum;
    sum += num;
  }

  cout << all - *max_element(a.begin(), a.end()) << '\n';
  return 0;
}

