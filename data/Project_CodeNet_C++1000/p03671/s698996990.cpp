#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  cout << min({abs(a + b), abs(b + c), abs(c + a)}) << endl;

  return 0;
}
