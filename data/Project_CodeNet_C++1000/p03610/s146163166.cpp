#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string s, t;
  cin >> s;

  int size;
  if( s.size() % 2 == 0 )
    size = s.size() / 2;
  else
    size = ( s.size() + 1 ) / 2;

  for( int i = 0; i < size; i++ )
  cout << s.at( 2 * i );
}