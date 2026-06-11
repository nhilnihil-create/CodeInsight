#include<bits/stdc++.h>
using namespace std;

int count2( int i );

int main( void )
{
  int N;
  cin >> N;
  int max = -INT_MAX;
  int count;
  int maxi;
  for( int i = 1; i <= N; i++ ) {
    count = count2( i );
    //cout << count << endl;
    if( count > max ) {
      max = count;
      maxi = i;
    }
  }

  cout << maxi << endl;
}

int count2( int i )
{
  int count = 0;
  while( 1 ) {
    if( i % 2 == 0 ) {
      count++;
      i /= 2;
    }
    else
      break;
  }
  return count;
}