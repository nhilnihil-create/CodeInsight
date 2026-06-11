#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> a(N);
  for (int i=0; i<N; ++i) cin >> a[i];
  
  vector<long long> dpf(N), dpb(N), sum(N+1);
  for (int i=1; i<N; ++i) {
    dpf[i] = dpf[i-1];
    if (a[i-1] > 0) dpf[i] += a[i-1];
  }
  for (int i=N-2; i>=0; --i) {
    dpb[i] = dpb[i+1];
    if (a[i+1] > 0) dpb[i] += a[i+1];
  }
  for (int i=1; i<N+1; ++i) {
    sum[i] = sum[i-1] + a[i-1];
  }
  
  long long res = 0;
  for (int i=0; i<N-K+1; ++i) {
    long long tmp = max(0LL, sum[i+K] - sum[i]) + dpf[i] + dpb[i+K-1];
    if (res < tmp) res = tmp;
  }
  cout << res << endl;
  return 0;
}


  
  