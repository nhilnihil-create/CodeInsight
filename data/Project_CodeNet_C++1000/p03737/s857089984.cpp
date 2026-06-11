#include <iostream>
#include <string>

using namespace std;

int main()	{
  string a, b, c;
  cin >> a >> b >> c;
  cout << char(a[0] - 'a' + 'A') << char(b[0] - 'b' + 'B') << char(c[0] - 'c' + 'C') << endl;
  return 0;
}