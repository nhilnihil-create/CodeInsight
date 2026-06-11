#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll ans = 0;
  REP(i, N) { cin >> A[i]; }
  for (int i = 1; i < N; i++) {
    if (A[i - 1] % 2 == 0) continue;
    if (A[i] > 0) {
      ans++;
      A[i - 1]--, A[i]--;
    }
  }
  REP(i, N) { ans += A[i] / 2; }
  cout << ans << endl;
}