#include<iostream>
using namespace std;

const int MOD = 1000000007;

int T[100010], A[100010], dp[100010];

int main() {
  int N; cin>>N;
  for (int i = 0; i < N; i++) cin >> T[i];
  for (int i = 0; i < N; i++) cin >> A[i];
  if (A[0] != T[N-1]) { cout<<0<<endl; return 0; }
  for (int i = 0; i < N; i++) dp[i] = 0;
  int prev_t = 0;
  for (int i = 0; i < N; i++) {
    if (T[i] != prev_t) {
      if (A[i] < T[i]) { cout<<0<<endl; return 0; }
      dp[i] = T[i];
    }
    prev_t = T[i];
  }
  int prev_a = 0;
  for (int i = N-1; i >= 0; i--) {
    if (A[i] != prev_a) {
      if (T[i] < A[i] || (dp[i]!=0 && dp[i]!=A[i])) { cout<<0<<endl; return 0; }
      dp[i] = A[i];
    }
    prev_a = A[i];
  }
  long prod = 1;
  for (int i = 0; i < N; i++) {
    if (dp[i] == 0) {
      prod = prod * min(T[i], A[i]) % MOD;
    }
  }
  cout<<prod<<endl;
}