#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  string a[55][55], b[55][55];
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, (int)s.size()) a[i][j] = s[j];
  }
  rep(i, m) {
    string s;
    cin >> s;
    rep(j, (int)s.size()) b[i][j] = s[j];
  }

  rep(i, n-m+1) rep(j, n-m+1) {
    bool match = true;
    rep(k, m) {
      rep(l, m) {
        if (a[i+k][j+l] != b[k][l]) {
          match = false;
          break;
        }
      }
      if (!match) break;
    }
    // remaining match == true at this point infers that some part of image a perfectly matched to image b
    if (match) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}