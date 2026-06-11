
#include<bits/stdc++.h>
using namespace std;
int
main ()
{
  int n, m;
  cin >> n >> m;
  if (n == 1)
    {
      n = 14;
    }
  if (m == 1)
    {
      m = 14;
    }
  if (n == m)
    {
      cout << "Draw";
    }
  else if (n < m)
    {
      cout << "Bob";
    }
  else
    {
      cout << "Alice";
    }
  return 0;
}