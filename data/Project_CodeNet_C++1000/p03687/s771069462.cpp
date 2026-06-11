#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  char c;
  int tmp = 0, maxs = 0, res = s.size();
  for (int i = 0; i < 26; i++)
  {
    for (int j = 0; j < s.size(); j++)
    {
      c = i + 97;
      if (s.at(j) == c)
      {
        maxs = max(tmp, maxs);
        tmp = 0;
      }
      else if (j == s.size() - 1)
      {
        tmp++;
        maxs = max(tmp, maxs);
      }
      else
      {
        tmp++;
      }
    }
    res = min(maxs, res);
    tmp = 0;
    maxs = 0;
  }
  cout << res << endl;
}