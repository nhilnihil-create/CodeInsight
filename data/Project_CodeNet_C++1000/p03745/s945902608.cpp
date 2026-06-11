#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() { 
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    ans++;
    if (A[i] == A[i+1]) {
      while (A[i] == A[i+1]) {
        i++;
        if (i == N - 1) break;
      }
    }
    if (A[i] < A[i+1]) {
      while (A[i] <= A[i+1]) {
        i++;
        if (i == N - 1) break;
      }
      if (i == N - 1) break;
      if (i == N - 2 && A[i] > A[i+1]) ans++;
      continue;
    }
    if (A[i] > A[i+1]) {
      while (A[i] >= A[i+1]) {
        i++;
        if (i == N - 1) break;
      }
      if (i == N -1) break;
      if (i == N - 2 && A[i] < A[i+1]) ans++;
    }
  }
  if (N == 1) ans++;
  cout << ans << endl;
  return 0;
}