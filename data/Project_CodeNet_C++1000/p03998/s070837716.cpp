#include <iostream>
#include <string>

using namespace std;
int main()
{
  int j = 0;
  string player = "abc";
  string strlist[3], str;
  for (int i = 0; i < 3; i++) cin >> strlist[i];

  while (true)
  {
    if (strlist[j].length() == 0)
    {
      cout << (char)toupper(player[j]);
      break;
    }
    str = strlist[j][0];
    strlist[j].erase(0, 1);
    j = player.find(str[0]);
  }

  cin >> j;
  return 0;
}
