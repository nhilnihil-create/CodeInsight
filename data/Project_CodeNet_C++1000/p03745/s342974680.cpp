#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  if (N <= 2) {
    cout << 1 << endl;
    return 0;
  }
  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  int mode = -1;
  if (A[0] < A[1]) {
    mode = 0;
  } else if (A[0] > A[1]) {
    mode = 1;
  }
  for (int i = 2; i < N; i++) {
    if (mode == -1 && A[i-1] > A[i]) {
      mode = 1;
    } else if (mode == -1 && A[i-1] < A[i]) {
      mode = 0;
    }
    if (mode == 0 && A[i-1] > A[i]) {
      ans++;
      mode = -1;
    } 
    if (mode == 1 && A[i-1] < A[i]) {
      ans++;
      mode = -1;
    } 
  }
  cout << ans + 1 << endl;
  return 0;
}