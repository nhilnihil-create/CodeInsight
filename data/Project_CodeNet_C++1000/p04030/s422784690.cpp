#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s; cin >> s;
  string ans = "";
  for (auto &&c : s)
  {
    if (c == '1')
    {
      ans.push_back('1');
    }
    if (c == '0')
    {
      ans.push_back('0');
    }
    if (c == 'B' && !ans.empty())
    {
      ans.pop_back();
    }
    
  }
  cout << ans << endl;
}