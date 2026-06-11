#include <iostream>

using namespace std;

bool func ( int n )
{
  while ( n > 0 ) {
    if ( n % 10 == 9 ) return true;
    n /= 10;
  }

  return false;
}

int main()
{
  int n;

  cin >> n;

  if ( func(n) ) cout << "Yes\n";
  else cout << "No\n";
}
