#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  vector<int> v(26, 0);

  for (int i = 0; i < s.size(); i++)
  {
    int a = s[i] - 97;
    v.at(a)++;
  }

  char ans = 'a';

  for (int i = 0; i < 26; i++)
  {
    if (v.at(i) == 0)
    {
      ans += i;
      break;
    }
    if (i == 25)
    {
      cout << "None" << endl;
      return 0;
    }
  }

  cout << ans << endl;
}