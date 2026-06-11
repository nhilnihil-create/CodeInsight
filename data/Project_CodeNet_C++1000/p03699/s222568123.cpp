#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, sum = 0;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++)
  {
    cin >> s.at(i);
    sum += s.at(i);
  }
  sort(s.begin(), s.end());
  for (int i = 0; i < n; i++)
  {
    if (s.at(i) % 10 != 0)
    {
      break;
    }
    if (i == n - 1)
    {
      cout << 0 << endl;
      return 0;
    }
  }

  if (sum % 10 == 0)
  {
    for (int i = 0; i < n; i++)
    {
      if (s.at(i) % 10 != 0)
      {
        sum -= s.at(i);
      }
      if (sum % 10 != 0)
      {
        break;
      }
    }
  }
  cout << sum << endl;
}
