#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

long long ans = 0;
void solve(string S, long long n)
{
  ans += (n + stoll(S));
  for (int i = 1; i <= S.size() - 1; i++)
  {
    solve(S.substr(i), n + stoll(S.substr(0, i)));
  }
}

int main()
{
  string S;
  cin >> S;
  int n = S.size();
  solve(S, 0);
  cout << ans << endl;
}