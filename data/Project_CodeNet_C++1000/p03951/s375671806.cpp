//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i <= n; i++) {
    string u = s + t.substr(n-i, i);
    int m = u.size();
    if (u.substr(m-n, n) == t) {
      cout << u.size() << endl;
      return 0;
    }
  }
}