#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main()
{
  string s; cin >> s;
  map<char, int> mp;
  for (auto &&v : s)
  {
    mp[v]++;
  }
  char c = 'a';
  for (auto &&v : mp)
  {
    if (v.first == c)
    {
      c++;
    }
    else
    {
      cout << c << endl;
      return 0;
    }
    
  }
  if (c == 'z' + 1)
  {
    cout << "None" << endl;
  }
  else
  {
    cout << c << endl;
  }
  
  
  
}