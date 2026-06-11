#include <iostream>
#include <string>

using namespace std;

bool even(string s)	{
  string x = s.substr(0, s.length() / 2);
  int j = 0;
  for (int i = s.length() / 2; i < s.length(); i++)	{
    if (x[j] != s[i])	{
      return false;
    }
    j++;
  }
  return true;
}

int main()	{
  string s;
  cin >> s;
  s.pop_back();
  s.pop_back();
  while (!even(s))	{
    s.pop_back();
    s.pop_back();
  }
  cout << s.length() << endl;
  return 0;
}