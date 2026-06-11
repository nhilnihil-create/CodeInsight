#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[1000];
  int min, max;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (i == 0)
    {
      min = a[i];
      max = a[i];
    }
    else
    {
      if (max < a[i])
        max = a[i];
      if (min > a[i])
        min = a[i];
    }
  }
  int c[1000] = { 0 };
  int k = 0;
  for (int i = min; i <= max; i++, k++)
  {
    for (int j = 0; j < n; j++)
    {
      c[k] += (i - a[j]) * (i - a[j]);
    }
  }
  sort(c, c + k);
  cout << c[0] << endl;
}