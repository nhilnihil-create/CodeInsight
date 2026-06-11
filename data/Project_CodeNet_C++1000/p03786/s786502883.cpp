#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  int N;
  cin >> N;
  
  vector<ll> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());
  
  vector<ll> sum(N+1, 0);
  
  for (int i = 0; i < N; i++) {
    sum[i+1] = sum[i] + a[i];
  }
  
  
  int ans = 1;
  
  for (int i = N-1; i >= 1; i--) {
    if (a[i] > 2 * sum[i]) {
      break;
    }
    ans++;

  }
  
  cout << ans << endl;
}