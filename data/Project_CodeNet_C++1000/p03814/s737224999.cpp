#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string s;
  cin >> s;
  int atA, atZ;
  
  atA = INT_MAX;
  atZ = -INT_MAX;
  for( int i = 0; i < s.size(); i++ ) {
    if( s.at( i ) == 'A' && i < atA )
      atA = i;
    if( s.at( i ) == 'Z' && i > atZ )
      atZ = i;
  }

  cout << atZ - atA + 1 << endl;
}