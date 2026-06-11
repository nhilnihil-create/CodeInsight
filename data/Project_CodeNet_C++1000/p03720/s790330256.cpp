#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, m) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  vector<int> c(n, 0);
  rep(i, m) {
    ++c[a[i]];
    ++c[b[i]];
  }
  rep(i, n) cout << c[i] << endl;
  return 0;
}