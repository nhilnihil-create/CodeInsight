#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  int N;
  cin >> N;
  
  
  vector<ll> A(N), B(N);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  
  ll ans = 0;
  
  for (int i = N-1; i >= 0; i--) {
    if ((A[i]+ans) % B[i]) {
      ans += B[i] - ((A[i]+ans) % B[i]);
    }
  }
  
  cout << ans << endl;
}