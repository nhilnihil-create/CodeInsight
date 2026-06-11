#include <iostream>

using namespace std;

int main()	{
  int w, a, b;
  cin >> w >> a >> b;
  if (a < b)	{
    int temp = b - a - w;
    if (temp > 0) cout << temp << endl;
    else cout << 0 << endl;
  }
  else if (b < a)	{
    int temp = a - b - w;
    if (temp > 0) cout << temp << endl;
    else cout << 0 << endl;
  }
  else	{
    cout << 0 << endl;
  }
  return 0;
}
