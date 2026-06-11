#include <iostream>


using namespace std;

int main()	{
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c;
  if (a + b == c || b + c == a || c + a == b)	{
  	cout << "Yes\n";
  }
  else	{
    cout << "No\n";
  }
  return 0;
}