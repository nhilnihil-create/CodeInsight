#include <bits/stdc++.h>
#define FOR(i, b, n) for (long i = b; i < n; ++i)

using namespace std;

void solve(string S) {
  long ans(0);
  FOR(i, 1, S.length())
    if (S[i] != S[i - 1])
      ans++;
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  solve(S);

  return 0;
}
