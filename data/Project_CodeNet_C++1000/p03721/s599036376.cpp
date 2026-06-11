#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vector<P> v(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    v[i].first = a;
    v[i].second = b;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); ++i) {
    k -= v[i].second;
    if (k <= 0) {
      cout << v[i].first << endl;
      break;
    }
  }
  
  return 0;
}