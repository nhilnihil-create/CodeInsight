#include<iostream>
using namespace std;
int main()
{
  int c, a, b;
  cin >> a >> b >> c;
  if(a + b <= b + c && a + b <= a + c)
    cout << a + b;
  else if(b + c <= a + c && b + c <= a + b)
    cout << b + c;
  else if(a + c <= b + c && a + c <= a + b)
    cout << a + c;
  return 0;
}