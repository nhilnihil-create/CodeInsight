#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  vector<int> A(26, 0);
  for (int i = 0; i < (int)S.size(); i++)
  {
    A.at((int)(S.at(i) - 'a'))++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (A.at(i) == 0)
    {
      cout << (char)('a' + i) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}