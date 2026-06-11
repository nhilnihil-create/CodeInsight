#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
long long MOD = 1000000007;
int main(){
  int N;
  cin >> N;
  vector<int> T(N);
  for (int i = 0; i < N; i++){
    cin >> T[i];
  }
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<int> m(N, 1);
  vector<int> M(N, INF);
  M[0] = min(M[0], T[0]);
  m[0] = max(m[0], T[0]);
  for (int i = 1; i < N; i++){
    if (T[i - 1] < T[i]){
      M[i] = min(M[i], T[i]);
      m[i] = max(m[i], T[i]);
    } else {
      M[i] = min(M[i], T[i]);
    }
  }
  M[N - 1] = min(M[N - 1], A[N - 1]);
  m[N - 1] = max(m[N - 1], A[N - 1]);
  for (int i = N - 2; i >= 0; i--){
    if (A[i] > A[i + 1]){
      M[i] = min(M[i], A[i]);
      m[i] = max(m[i], A[i]);
    } else {
      M[i] = min(M[i], A[i]);
    }
  }
  long long ans = 1;
  for (int i = 0; i < N; i++){
    ans *= max(M[i] - m[i] + 1, 0);
    ans %= MOD;
  }
  cout << ans << endl;
}