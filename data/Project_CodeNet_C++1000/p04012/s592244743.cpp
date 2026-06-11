#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string w;
  cin >> w;
  vector<int> a(26, 0);
  rep(i, w.size()) ++a[w[i] - 'a'];
  bool b = true;
  rep(i, 26) if (a[i] % 2 == 1) b = false;
  if (b) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}