#include <bits/stdc++.h>
using namespace std;

int main()
{
  long double a, b;
  cin >> a >> b;
  if (a > b)
  {
    cout << "GREATER" << endl;
  }
  else if (b > a)
  {
    cout << "LESS" << endl;
  }
  else
  {
    cout << "EQUAL" << endl;
  }
}
