#include<iostream>
using namespace std;
int main()
{
  char a, b;
  cin >> a >> b;
  if(b == 'H')
  {
    if(a == 'H')
      cout << "H";
    else 
      cout << "D";
  }
  if(b == 'D')
  {
    if(a == 'D')
      cout << "H";
    else
      cout << "D";
  }
  return 0;
}