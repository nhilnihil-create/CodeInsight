#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K; cin >> N >> K;
  long long a[5011];
  for(int i = 0; i < N; ++i) {
    cin >> a[i];
  }
 
  sort(a, a + N);
 
  long long sum = 0;
  int ans = N;
  for(int i = N-1; i >= 0; --i) {
    if(sum + a[i] < K) sum += a[i];
    else ans = min(ans, i);
  }
  cout << ans << endl;
 
  return 0;
}

    