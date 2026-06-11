#include <bits/stdc++.h>
using namespace std;

int main()
{
 string s;
  cin >> s;
  bool f = true;
  if (s.length() < 4)
    f = false;
  if (s[0] != 'Y' || s[1] != 'A' || s[2] != 'K' || s[3] != 'I')
    f= false;
  
  if (f)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}