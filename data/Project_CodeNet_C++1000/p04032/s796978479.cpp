#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  bool cout_flag = false;
  cin >> str;
  for (int i = 0; i < str.length() - 1; i++)
  {
    if(str[i] == str[i + 1])
    {
      cout << i + 1 << " " << i + 2;
      cout_flag = true;
      break;
    }
    else if(i < str.length() - 2 && str[i] == str[i + 2])
    {
      cout << i + 1 << " " << i + 3;
      cout_flag = true;
      break;
    }
  }

  if (!cout_flag)
  {
    cout << "-1 -1";
  }

  return 0;
}
