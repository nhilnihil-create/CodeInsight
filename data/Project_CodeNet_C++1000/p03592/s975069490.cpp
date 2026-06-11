#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  rep(x,n+1) {
    rep(y,m+1) {
      if (k == x*(m-y)+y*(n-x)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
