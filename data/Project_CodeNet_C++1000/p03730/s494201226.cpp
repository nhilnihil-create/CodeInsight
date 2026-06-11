#include <iostream>

using namespace std;

int main()	{
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = a; i < b * a; i+=a)	{
    if ((i % b) == (c % b))	{
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}