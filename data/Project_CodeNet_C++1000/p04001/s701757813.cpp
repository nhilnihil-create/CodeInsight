#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

string s;
ll ans;

void func(ll t, ll sum, int c = 0)
{
  t *= 10;
  t += s[c] - '0';
  if (c == s.size() - 1)
  {
    ans += sum + t;
    return;
  }
  func(t, sum, c + 1);
  func(0, sum + t, c + 1);
  return;
}

int main()
{
  cin >> s;
  ans = 0;
  func(0, 0);
  cout << ans << endl;
  return 0;
}