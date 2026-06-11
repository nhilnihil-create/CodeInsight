#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll T[N],A[N];
  for (int i = 0; i < N; i++) {
    cin >> T[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if (N == 1) {
    if (A[0] == T[0]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
    return 0;
  }
  bool exist = true;
  int tmp = max(T[0],A[0]);
  for (int i = 0; i < N; i++) {
    if (max(A[i],T[i]) != tmp) {
      exist = false;
    }
  }
  for (int i = 1; i < N; i++) {
    if (T[i-1] != T[i]) {
      if (A[i] < T[i]) {
        exist = false;
      }
    }
  }
  for (int i = 0; i < N-1; i++) {
    if (A[i+1] != A[i]) {
      if (T[i] < A[i]) {
        exist = false;
      }
    }
  }
  if (!exist) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 1;
  for (int i = 0; i < N; i++) {
    if (i == 0 || i == N-1) {
      ans *= 1;
    } else {
      if (T[i-1] == T[i] && A[i] == A[i+1]) {
        ans *= min(T[i],A[i]);
        ans %= Mod;
      } else {
        ans *= 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
