#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans = 0;
  string s;
  cin >> s;
  char buf = s[0];
  for (int i = 1; i < s.size(); i++)
  {
    if (buf != s[i])
    {
      ans++;
      buf = s[i];
    }
  }
  cout << ans << endl;
}
