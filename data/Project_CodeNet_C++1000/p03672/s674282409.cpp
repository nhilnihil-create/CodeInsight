#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;

  while (1)
  {
    S.pop_back();

    string s1 = S.substr(0, (S.size() / 2));
    string s2 = S.substr(S.size() / 2);
    if (s1 == s2)
    {
      cout << S.size() << endl;
      return 0;
    }
  }
}
