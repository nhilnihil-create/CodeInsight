#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  
  int ans = 200000000000;
  for (int bit = 0; bit < (1 << N); ++bit) {
    vector<int> b(N);
    for (int i = 0; i < N; ++i) b[i] = a[i];
    
    vector<int> S;
    for (int i = 0; i < N; ++i) {
      if (bit & (1 << i)) S.push_back(i);
    }
    
    int cost = 0;
    for (int i : S) {
      int MAX = 0;
      for (int j = 0; j < i; ++j) MAX = max(b[j], MAX);
      if (MAX >= b[i]) {
        cost += MAX - b[i] + 1;
        b[i] = MAX + 1;
      }
    }
    
    int cnt = 0;
    int MAX;
    for (int i = 0; i < N; ++i) {
      if (i == 0) {
        ++cnt;
        MAX = b[i];
      } else {
        if (MAX < b[i]) ++cnt;
        MAX = max(b[i], MAX);
      }
    }
    
    if (cnt >= K) ans = min(cost, ans);
  }
  
  cout << ans << endl;
  return 0;
}