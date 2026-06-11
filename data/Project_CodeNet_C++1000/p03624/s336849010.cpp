#include <iostream>
#include <string>

using namespace std;

int main()	{
  string s;
  cin >> s;
  int n = s.length();
  int freq[27] = {0};
  for (int i = 0; i < n; i++)	{
    freq[int(s[i] - 'a')]++;
  }
  bool flag = false;
  for (int i = 0; i < 26; i++)	{
    if (freq[i] == 0)	{
      cout << char(i + 'a') << endl;
      flag = true;
      break;
    }
  }
  if (!flag)	{
    cout << "None" << endl;
  }
  return 0;
}