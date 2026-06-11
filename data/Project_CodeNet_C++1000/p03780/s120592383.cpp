#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int n, k; cin >> n >> k;
  vector<int> la;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    if (a >= k) continue;
    la.push_back(a);
  }
  sort(la.begin(), la.end());
  int n2 = la.size();
  int s[n2+1];
  s[0] = 0;
  for (int i = 0; i < n2; ++i) { 
    s[i+1] = s[i]+la[i];
  }
  int l = -1, r = la.size();
  while (r-l > 1) {
    int c = (l+r)/2;
    int v = la[c];
    auto check = [&](int x) {
      if (s[x] >= k) return false;
      int ma = k-s[x];
      vector<bool> dp(ma);
      dp[0] = true;
      for (int j = c+1; j < n2; ++j) { 
        for (int i = ma-1; i >= 0; --i) { 
          if (!dp[i]) continue;
          if (i >= ma-v) return false;
          if (i+la[j] < ma) dp[i+la[j]] = true;
        }
      }
      for (int i = ma-v; i < ma; ++i) {
        if (dp[i]) return false;
      }
      return true;
    };
    if (check(c)) l = c;
    else r = c;
  }
  cout << l+1 << endl;
}

