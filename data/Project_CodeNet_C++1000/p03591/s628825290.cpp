#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  int i;
  int ch = 0;
  string t = "YAKI";
  if(s.size() < 4)
  {
    ch = 1;
  }
  if(ch == 0)
  {
    for(i = 0; i < 4; i++)
    {
      if(s.at(i) != t.at(i))
      {
        ch = 1;
        break;
      }
    }
  }
  if(ch == 0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}