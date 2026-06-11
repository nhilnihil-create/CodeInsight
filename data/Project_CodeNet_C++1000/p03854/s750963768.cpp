#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() 
{
  string s,t;
  cin >> s;
  reverse(s.begin(),s.end());
  
  string ans = "YES";
  for(int i = 0; ; )
  {
    if(s.size() == 0) break;
    if(s.substr(0,2) == "re")
    {
      if(s.substr(0,6) == "resare")
        s.erase(0,6);
      else if(s.substr(0,7) == "remaerd")
        s.erase(0,7);
      else
      {
        ans = "NO";
        break;
      }
    }
    else
    {
      if(s.substr(0,5) == "esare")
        s.erase(0,5);
      else if(s.substr(0,5) == "maerd")
        s.erase(0,5);
      else
      {
        ans = "NO";
        break;
      }
    }
  }  
  cout << ans << endl;
}