#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i < n; ++i)

using namespace std;
using ll = long long;

void solve(long N, vector<long> a) {

  sort(a.rbegin(), a.rend());

  ll ans = 0;  
  REP(i, N)
    ans += a[2 * i + 1];
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;
  vector<long> a(3*N);
  REP(i, 3*N)
    cin >> a[i];

  solve(N, move(a));

  return 0;
}
