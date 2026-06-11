#include <iostream>

using namespace std;

int main()	{
  int a, b, c;
  cin >> a >> b;
  c = a + b;
  if (a % 3 == 0 || b % 3 == 0 || c % 3 == 0)	{
    cout << "Possible" << endl;
  }
  else {
    cout << "Impossible" << endl;
  }
  return 0;
}