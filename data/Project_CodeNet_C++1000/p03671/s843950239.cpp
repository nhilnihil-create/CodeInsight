#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c, total;

  cin >> a >> b >> c;

  total = a + b;

  if (total > b + c) {
    total = b + c;
  }
  if (total > a + c) {
    total = a + c;
  }

  cout << total << endl;
}
