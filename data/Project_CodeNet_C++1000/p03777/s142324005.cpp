#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a, b;

  cin >> a >> b;

  if (a == "H")
  {
    if (b == "H")
    {
      cout << "H"
           << "\n";
    }
    else
    {
      cout << "D"
           << "\n";
    }
  }
  else
  {
    if (b == "D")
    {
      cout << "H"
           << "\n";
    }
    else
    {
      cout << "D"
           << "\n";
    }
  }
}