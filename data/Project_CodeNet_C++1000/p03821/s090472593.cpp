#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i < n; ++i)

using namespace std;
using ll = long long;

void solve(long N, vector<long> A, vector<long> B) {
  ll ans = 0;
  REP(i, N) {
    const long j = N - i - 1;
    const long ext = (A[j] + ans) % B[j];
    if (ext)
      ans += B[j] - ext;
  }
  cout << ans << endl;
  
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;

  vector<long> A(N);
  vector<long> B(N);
  REP(i, N)
    cin >> A[i] >> B[i];

  solve(N, move(A), move(B));

  return 0;
}
