#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, k;
  cin >> n >> k;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    res += min(abs(x - 0), abs(x - k)) * 2;
  }

  cout << res << "\n";
}
