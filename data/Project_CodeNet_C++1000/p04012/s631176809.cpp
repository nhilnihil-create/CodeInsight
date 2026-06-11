#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std; //std::の省略のため
using ll = long long;

int main()
{

  string w;
  cin >> w;

  int count[26] = {};
  int n = w.size();
  int num;

  for (int i = 0; i < n; i++)
  {
    num = w[i] - 'a';
    count[num]++;
  }

  bool judge = true;

  for (int i = 0; i < 26; i++)
  {
    if (count[i] % 2 != 0)
    {
      judge = false;
      break;
    }
  }

  if (judge)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
