#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string S, T;
  cin >> S;

  reverse( S.begin(), S.end() );

  
  for( int i = 0; i < S.size(); i++ ) {
    T += S.at( i );
    //cout << "T:" << T << endl;
    if( T == "maerd" ) T = "";
    if( T == "remaerd" ) T = "";
    if( T == "esare" ) T = "";
    if( T == "resare" ) T = "";
  }

  if( T == "" )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}