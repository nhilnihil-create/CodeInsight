#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

string s;
string s2;
ll ans;

void calc()
{
  ll t1 = 0, t2 = 0;
  for (char c : s2)
    if (c != '+')
    {
      t1 *= 10;
      t1 += c - '0';
    }
    else
    {
      t2 += t1;
      t1 = 0;
    }
  ans += t1 + t2;
}

void func(int c)
{
  s2 += s[c];
  if (c == s.size() - 1)
  {
    calc();
    s2.pop_back();
    return;
  }
  func(c + 1);
  s2 += '+';
  func(c + 1);
  s2.pop_back();
  s2.pop_back();
  return;
}

int main()
{
  cin >> s;
  ans = 0;
  s2 = "";
  func(0);
  cout << ans << endl;
  return 0;
}