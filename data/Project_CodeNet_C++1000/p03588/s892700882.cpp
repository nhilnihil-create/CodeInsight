#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  int mi = 1e9+1;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (mi > b) {
      res = a + b;
      mi = b;
    }
  }
  cout << res << endl;
  return 0;
}