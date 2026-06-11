#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<int> cnt(n, 0);
  rep(i, m) {
    cnt[a[i]]++;
    cnt[b[i]]++;
  }
  rep(i, n) {
    cout << cnt[i] << endl;
  }
  return 0;
}