#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans = 1;
  string w;
  cin >> w;
  int W[26] = {0};
  for (int i = 0; i < w.size(); i++)
  {
    W[(int)w[i] - 97]++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (W[i] % 2 != 0)
    {
      ans = 0;
    }
  }
  if (ans)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
