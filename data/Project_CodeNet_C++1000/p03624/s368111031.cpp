#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  
  int alphabets[26] = {0};
  for(unsigned int i = 0; i < s.length(); ++i)
  {
    alphabets[s[i] - 'a']++;
  }

  bool flag = true;
  for(int i = 0; i < 26; ++i)
  {
    if(alphabets[i] == 0)
    {
      char c = 'a' + i;
      cout << c << endl;
      flag = false;
      break;
    }
  }
  if(flag) cout << "None" << endl;
}