#include <iostream>

using namespace std;

int main()	{
  char s[27];
  int freq[26] = {0};
  cin >> s;
  for (int i = 0; s[i] != '\0'; i++)	{
    freq[s[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)	{
    if (freq[i] > 1)	{
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
  return 0;
}