#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, M; cin >> N >> M;
  
  int64_t MOD = 1000000007;
  
  if (1 < abs(N - M)) { cout << 0 << endl; return 0; }
  
  if (abs(N - M) == 1) {
    
    int64_t tmpN = 1, tmpM = 1;
    
    for (int i = 1; i <= N; i++) {
      tmpN *= i; tmpN %= MOD;
    }
    
    for (int i = 1; i <= M; i++) {
      tmpM *= i; tmpM %= MOD;
    }
    
    cout << tmpN * tmpM % MOD << endl;
    
  }
  
  if (N == M) {
    
    int64_t tmpN = 1, tmpM = 1;
    
    for (int i = 1; i <= N; i++) {
      tmpN *= i; tmpN %= MOD;
    }
    
    for (int i = 1; i <= M; i++) {
      tmpM *= i; tmpM %= MOD;
    }
    
    cout << tmpN * tmpM % MOD * 2 % MOD << endl;
    
  }
  
}