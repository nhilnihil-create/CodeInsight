#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, x[101];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> x[i];
    
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp = min(x[i], K-x[i]);
    ans += tmp;
  }
  cout << 2 * ans << endl;
}