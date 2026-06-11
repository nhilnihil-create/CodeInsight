#include <iostream>
#include <string>

using namespace std;

int main()	{
  string a;
  cin >> a;
  char x = a[0];
  char y = a[a.length() - 1];
  cout << x << a.length() - 2<< y << endl;
  return 0;
}