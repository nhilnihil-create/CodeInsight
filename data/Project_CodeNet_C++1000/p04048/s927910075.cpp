#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)

int64_t count(int64_t a, int64_t b) {
  int64_t m = min(a, b);
  int64_t M = max(a, b);
  int64_t q = M / m;
  int64_t r = M % m;
  
  int64_t part = 2 * m * q;
  if ( r == 0 ) {
    return part - m;
  }
  else {
    return part + count(m, r);
  }
}

int64_t solve(int64_t N, int64_t X) {
  return N + count(N-X, X);
}

int main() {
  int64_t N, X;
  cin >> N >> X;
  int64_t answer = solve(N, X);
  cout << answer << endl;  
}