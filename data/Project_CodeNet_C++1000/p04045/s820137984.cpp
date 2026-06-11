#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  int k;
  cin >> n >> k;
  vector<int> d(10, 0);
  for (int i = 0; i < k; i++)
  {
    int buf;
    cin >> buf;
    d.at(buf) = 1;
  }

  for (int i = n; i < 100000; i++)
  {
    int flag = 1;
    int buf = i;
    while (buf != 0)
    {
      if (d.at(buf % 10) == 1)
      {
        flag = 0;
        break;
      }
      buf /= 10;
    }
    if (flag == 1)
    {
      cout << i << endl;
      break;
    }
  }
}
