#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  string S;
  cin >> S;

  string num;
  num =  to_string(S.size() - 2);
  
  string T = S.at( 0 ) + num + S.at( S.size() - 1 );

  cout << T << endl;
}
  