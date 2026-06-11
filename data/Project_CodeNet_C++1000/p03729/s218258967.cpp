#include <iostream>
#include <string>

using namespace std;

int main()	{
  string a, b, c;
  cin >> a >> b >> c;
  int x = a.length(), y = b.length(), z = c.length();
  if (a[x - 1] == b[0] && b[y - 1] == c[0])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}