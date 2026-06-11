#include <iostream>
#include <string>

using namespace std;

int main()	{
  string s;
  cin >> s;
  int n = s.length();
  int apos = n - 1;
  int zpos = 0;
  for (int i = 0; i < n; i++)	{
    if (s[i] == 'A')
      apos = min(apos, i);
    if (s[i] == 'Z')
      zpos = max(zpos, i);
  }
  cout << zpos - apos + 1 << endl;
  return 0;
}