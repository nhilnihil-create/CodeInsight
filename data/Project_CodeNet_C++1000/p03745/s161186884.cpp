#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve(long N, vector<long> A) {
  long ans = 1;
  enum {INC, DEC, FLAT};
  int state = FLAT;
  FOR(i, 1, N) {
    switch (state) {
    case FLAT:
      if (A[i] > A[i - 1])
	state = INC;
      else if (A[i] < A[i - 1])
	state = DEC;
      break;
    case INC:
      if (A[i] < A[i - 1]) {
	ans++;
	state = FLAT;
      }
      break;
    case DEC:
      if (A[i] > A[i - 1]) {
	ans++;
	state = FLAT;
      }
      break;
    }
  }
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;
  vector<long> A(N);
  REP(i, N)
    cin >> A[i];

  solve(N, move(A));

  return 0;
}
