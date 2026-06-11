#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
 
int main()
{
  string s;
  cin >> s;
  int l = s.length();
  
  string p[4] = {"dream", "dreamer", "erase", "eraser",};
  bool q[l+10];
  REP(i, l+10) q[i] = false;
  q[0] = true;
  REP(i, l)
  {
    if(q[i])
    {
      REP(j, 4)
      {
        if(s.substr(i, p[j].length()) == p[j])
        {
          q[i + p[j].length()] = true;
        }
      }
    }
  }
  cout << (q[l] ? "YES" : "NO") << endl;
  return 0;
}