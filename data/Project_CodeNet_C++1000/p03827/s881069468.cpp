#include <iostream>
using namespace std;
int main()
{
  char c;
  int n, x = 0, max = 0;
  cin >> n;
  while( cin >> c )
  {
    if( c == 'I' )
      x++;
    else
      x--;
    if( max < x ) 
      max = x;
  }
  cout << max;
}