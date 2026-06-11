#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i < n; ++i)

using namespace std;
using ll = long long;
using P = pair<int, int>;

void chmin(ll& a, ll b) {
  if (a > b)
    a = b;
}
void solve(ll A, ll B, ll C) {

  if ((A % 2) * (B % 2) * (C % 2) == 0)
    cout << 0 << endl;
  else
    cout << min(A * B, min(B * C, C * A)) << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;

  solve(A, B, C);

  return 0;
}
