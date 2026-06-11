#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;

  vector<bool> num(26);
  for (int i = 0; i < 26; i++)
  {
    num.at(i) = false;
  }

  for (int i = 0; i < s.size(); i++)
  {
    num.at(s.at(i) -'a') = true;
  }
  
  for (int i = 0; i < 26; i++)
  {
    if(!num.at(i)){
      char ans = i + 'a';
      cout << ans << endl;
      return 0;
    }
  }

  puts("None");
}
