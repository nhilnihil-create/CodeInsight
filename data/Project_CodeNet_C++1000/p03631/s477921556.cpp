#include <iostream>

using namespace std;

int main()	{
  int a;
  cin >> a;
  if (a / 100 == a % 10)	{
    cout << "Yes" << endl;
  }
  else	{
    cout << "No" << endl;
  }
  return 0;
}