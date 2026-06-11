#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin >> s;
  vector<char> Ans;
  for (int i = 0; i < s.size(); i++)
  {
    switch (s.at(i))
    {
    case '0':
      Ans.push_back('0');
      break;
    case '1':
      Ans.push_back('1');
      break;
    case 'B':
      if (Ans.size() > 0)
      {
        Ans.pop_back();
      }
      break;
    default:
      break;
    }
  }
  for (int i = 0; i < Ans.size(); i++)
  {
    cout << Ans.at(i);
  }
  cout << endl;
}
