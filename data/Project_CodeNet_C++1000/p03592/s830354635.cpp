#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int n, m, K;
  cin >> n >> m >> K;
  rep(i,n+1) {
    rep(j,m+1) {
      if(i*(m-j)+(n-i)*j==K) {
        cout << "Yes" << endl;
        return 0;
      }
    }

  }

  cout << "No" << endl;
  return 0;
}
