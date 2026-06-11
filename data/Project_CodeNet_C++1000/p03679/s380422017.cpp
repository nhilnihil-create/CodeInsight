#include <iostream>

using namespace std;

int main()	{
  long long x, a, b;
  cin >> x >> a >> b;
  if (a >= b)	{
    cout << "delicious" << endl;
  }
  else if (a < b && (b - a) <= x)	{
    cout << "safe" << endl;
  }
  else	{
    cout << "dangerous" << endl;
  }
  return 0;
}