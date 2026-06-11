#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

ll factorial(ll a) {
  if (a == 1) return 1;
  
  return (a * factorial(a-1)) % MOD;
}

int main() {
  ll N, M;
  cin >> N >> M;
  
  if (abs(N-M) > 1) {
    cout << 0 << endl;
  } else if (abs(N - M) == 1) {
    cout << (factorial(max(M, N)) * factorial(min(M,N))) % MOD << endl;
  } else {
    cout << (2 * factorial(N) * factorial(M)) % MOD << endl; 
  }
  
  
  
}