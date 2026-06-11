#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int chars[26] = {0};
  bool flag = true;
  for(unsigned int i = 0; i < s.length(); ++i)
  {
    if(chars[s[i] - 'a'] != 0)
    {
      flag = false;
      break;
    }
    chars[s[i] - 'a']++;
  }
  
  if(flag) cout << "yes" << endl;
  else cout << "no" << endl;
}