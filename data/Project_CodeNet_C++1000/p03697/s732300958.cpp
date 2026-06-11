#include <iostream>

using namespace std;

int main()	{
  int a, b;
  cin >> a >> b;
  int c = a + b;
  if (c >= 10)	{
    cout << "error" << endl;
  }
  else
    cout << c << endl;
  return 0;
}