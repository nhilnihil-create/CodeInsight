#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> color(9, 0);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    if (a < 400)
    {
      color.at(0) = 1;
    }
    else if (a < 800)
    {
      color.at(1) = 1;
    }
    else if (a < 1200)
    {
      color.at(2) = 1;
    }
    else if (a < 1600)
    {
      color.at(3) = 1;
    }
    else if (a < 2000)
    {
      color.at(4) = 1;
    }
    else if (a < 2400)
    {
      color.at(5) = 1;
    }
    else if (a < 2800)
    {
      color.at(6) = 1;
    }
    else if (a < 3200)
    {
      color.at(7) = 1;
    }
    else if (a >= 3200)
    {
      color.at(8)++;
    }
  }
  int min, max;
  min = max = 0;

  for (int i = 0; i < 8; i++)
  {
    if (color.at(i))
    {
      min++;
      max++;
    }
  }
  if (min == 0 && max == 0)
  {
    min = 1;
  }

  // if (max + color.at(8) > 8)
  // {
  //   max = 8;
  // }
  // else
  // {
  max += color.at(8);
  // }
  cout << min << " " << max << endl;
}
