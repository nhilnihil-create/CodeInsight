#include <iostream>

using namespace std;

int main()	{
  long long s, c;
  cin >> s >> c;
  if (s > c / 2) {cout << c / 2 << endl; return 0;}
  c = (c - (2 * s)) / 4;
  cout << s + c << endl;
  return 0;
}
