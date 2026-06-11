#include <iostream>
using namespace std;
int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e = a*b, f = c*d;
  if( e > f )
    cout << e << "\n";
  else
    cout << f << "\n";
}