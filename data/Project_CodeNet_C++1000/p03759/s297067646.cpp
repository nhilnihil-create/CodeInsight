#include <string>
#include <math.h>
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  int x = c - b;
  int y = b - a;
  if (x == y)
    cout << "YES";
  else
    cout << "NO";
}