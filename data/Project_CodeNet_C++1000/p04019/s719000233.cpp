#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;cin>>s;
  map<char,int> mp;
  for (auto &&c : s)
  {
    if (c=='N')
    {
      mp['N']++;
    }
    if (c=='W')
    {
      mp['W']++;
    }
    if (c=='S')
    {
      mp['S']++;
    }
    if (c=='E')
    {
      mp['E']++;
    }
    
  }
  if ((bool)(mp.count('N'))==(bool)(mp.count('S')) && (bool)(mp.count('E'))==(bool)(mp.count('W')))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  
  
}