#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()	{
  string input;
  string dream = "maerd";
  string dreamer = "remaerd";
  string erase = "esare";
  string eraser = "resare";
  cin >> input;
  reverse(input.begin(), input.end());
  //cout << input << endl;
  bool flag = true;
  while (flag && input.length() > 0)	{
    if (input.substr(0, 5) == dream)	{
      input = input.substr(5);
      continue;
    }
    else if (input.substr(0, 7) == dreamer)	{
      input = input.substr(7);
      continue;
    }
    else if (input.substr(0, 5) == erase)	{
      input = input.substr(5);
      continue;
    }
    else if (input.substr(0, 6) == eraser)	{
      input = input.substr(6);
      continue;
    }
    flag = false;
  }
  if (flag == false && input.length() > 0)	{
    cout << "NO" << endl;
  }
  else	{
    cout << "YES" << endl;
  }
  return 0;
}