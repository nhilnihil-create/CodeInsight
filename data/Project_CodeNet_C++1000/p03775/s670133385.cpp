#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  long long N;
  cin >> N;
  int ans = 100; //初期値は十分大きくしておく
  
  for (long long i=1; i*i<=N; i++) {
    if (N % i != 0) continue;
    long long A,B;
    A = i;
    B = N/i;
    int ketaA = 1; int ketaB = 1;
    while (A/10 > 0) {
      ketaA++;
      A /= 10;
    }
    while (B/10 > 0) {
      ketaB++;
      B /= 10;
    }
    ans = min(ans, max(ketaA, ketaB));
  }
    
  
  cout << ans << endl;
  return 0;
}