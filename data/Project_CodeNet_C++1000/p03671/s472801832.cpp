#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()	{
  int a, b, c;
  cin >> a >> b >> c;
  int maximum = max(a, max(b, c));
  cout << a + b + c - maximum << endl;
  return 0;
}