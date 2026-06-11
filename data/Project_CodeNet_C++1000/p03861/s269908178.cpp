#include <iostream>

using namespace std;

int main()	{
  unsigned long long a, b, c;
  cin >> a >> b >> c;
  unsigned long long x = (a - 1) / c;
  if (a == 0) x = -1;
  unsigned long long y = b / c;
  cout << y - x << endl;
  return 0;
}