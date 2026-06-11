#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

bool judge(int idx, string &s)
{
  int len = s.size();
  if (idx == len)
  {
    return true;
  }

  bool flag1 = false;
  bool flag2 = false;
  bool flag3 = false;
  if (idx + 5 <= len && (s.compare(idx, 5, "dream") == 0 || s.compare(idx, 5, "erase") == 0))
  {
    flag1 = true;
  }
  if (idx + 7 <= len && (s.compare(idx, 7, "dreamer") == 0))
  {
    flag2 = true;
  }
  if (idx + 6 <= len && (s.compare(idx, 6, "eraser") == 0))
  {
    flag3 = true;
  }
  return (flag1 ? judge(idx + 5, s) : false) || (flag2 ? judge(idx + 7, s) : false) || (flag3 ? judge(idx + 6, s) : false);
}

int main()
{
  string s;
  cin >> s;
  if (judge(0, s))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}