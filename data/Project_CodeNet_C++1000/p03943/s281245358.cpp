#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
  int a, b, c;
  cin >> a >> b >> c;
  int t = a;
  if (t < b)
    t = b;
  if (t < c)
    t = c;
  if (2 * t == a + b + c)
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
};