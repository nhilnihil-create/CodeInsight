#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()	{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b <= c || d <= a)	{
    cout << 0 << endl;
  }
  else	{
  	cout << abs(max(a, c) - min(b, d)) << endl;
  }
  return 0;
}