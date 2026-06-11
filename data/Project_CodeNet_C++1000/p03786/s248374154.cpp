#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> sz(N),Msz(N);
  for (int i = 0; i < N; i++) cin >> sz[i];
  sort(sz.begin(), sz.end());
  
  for (int i = 0; i < N; i++) {
    if (i == 0) Msz[i] = sz[i];
    else Msz[i] = sz[i] + Msz[i-1];
  }
  
  long long ans = 1;
  for (int i = N-1; i >= 1; i--) {
    if (sz[i] > Msz[i-1] * 2) break;
    ans++;
  }
  
  cout << ans << endl;
}