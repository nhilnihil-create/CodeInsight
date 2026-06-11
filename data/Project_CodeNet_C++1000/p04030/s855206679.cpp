#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  stack<char> stk, ans;
  for (int i = 0; i < (int)(S.size()); i++)
  {
    if (S.at(i) == '0')
    {
      stk.push('0');
    }
    else if (S.at(i) == '1')
    {
      stk.push('1');
    }
    else
    {
      if (!stk.empty())
      {
        stk.pop();
      }
    }
  }
  while (stk.size())
  {
    ans.push(stk.top());
    stk.pop();
  }
  while (ans.size())
  {
    cout << ans.top();
    ans.pop();
  }
  cout << endl;
}