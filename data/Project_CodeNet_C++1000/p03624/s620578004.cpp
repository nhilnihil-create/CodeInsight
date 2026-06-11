#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string S;
  cin >> S;
  vector<bool> alf( 1024 );
  int count = 0;

  for( int i = 0; i < 1024; i++ )
    alf.at( i ) = false;

  for( int i = 0; i < S.size(); i++ )
    alf.at( S.at( i ) - 'a' ) = true;

  for( int i = 0; i < 26; i++ ) {
    if( !alf.at( i ) ) {
      cout << (char)( i + 'a' ) << endl;
      break;
    }
    count++;
  }

  if( count == 26 )
    cout << "None" << endl;
}