#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s,res;
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='0' || s[i]=='1')
      res+=s[i];
    else if(s[i]=='B' && res.length()>0)
      res.erase(res.length()-1,1);
  }
  cout<<res;
  return 0;
}