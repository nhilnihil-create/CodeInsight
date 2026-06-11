#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N;
  cin >> N;
  vector<int> a( N );
  int point = 0;
  bool can = false;
  int count = 0;

  for( int i = 0; i < N; i++ ) 
    cin >> a.at( i );

  for( int i = 0; i < N; i++ ) {
    point = a.at( point ) - 1;
    count++;
    if( point == 1 ) {
      can = true;
      break;
    }
  }

  if( can )
    cout << count << endl;
  else
    cout << -1 << endl;
}
    