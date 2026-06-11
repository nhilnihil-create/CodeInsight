// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 200003;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  bool ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    ans ^= (x & 1) == 1;
  }
  cout << (ans ? "NO" : "YES") << endl;
  return 0;
}
