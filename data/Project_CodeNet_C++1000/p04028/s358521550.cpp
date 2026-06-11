#include<bits/stdc++.h>
using namespace std;

using I = long long;
const I M = 1e9 + 7;

I power(I m, I n) {
  if(!n) return 1;
  return (n & 1) ? (power(m, n - 1) * m % M) : power(m * m % M, n >> 1);
}
I inverse(I n) {
  return power(n, M - 2);
}

int main() {
  I N;
  string S;
  cin >> N >> S;

  vector<I> dp(N+1);
  dp[0] = 1;
  for(auto i=0; i<N; ++i) {
    vector<I> nex(N+1);
    for(auto j=0; j<N; ++j) {
      (nex[j+1] += 2 * dp[j]) %= M;
      (nex[max(0,j-1)] += dp[j]) %= M;
    }
    swap(nex, dp);
  }

  cout << dp[S.size()] * inverse(power(2, S.size())) % M<< endl;
}
