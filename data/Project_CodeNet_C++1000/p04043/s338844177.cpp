#include <iostream>
using namespace std;

int main()
{
  int a = 0, b = 0, c = 0;
  int total = 0;
  
  cin >> a >> b >> c;
  
  total = a+b+c;
  if(total==17 && a%2!=0 && b%2!=0 && c%2!=0)
    cout << "YES";
  else
    cout << "NO";
}