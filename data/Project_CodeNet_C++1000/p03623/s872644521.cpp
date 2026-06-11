#include <iostream>
using namespace std;

int main()
{
  int x;
  int a;
  int b;
  
  cin >> x;
  cin >> a;
  cin >> b;
  
  if(abs(x-a) < abs(x-b))
    cout << "A";
  else
    cout << "B";
}