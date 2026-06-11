#include<bits/stdc++.h>
using namespace std;

int checkSize( int X );
int F( int A, int B );

int main( void )
{
  long int N;
  int max, min;
  long int A, B;
  
  cin >> N;
  
  min = 1000;

  for( long int i = 1; i * i <= N; i++ ) {
    
    //test
    //cout << i << endl;
    
    if( i * ( N / i ) == N ) {
      A = i;
      B = N / i;
      
      //if( A > B )
      //break;
      if( N % A != 0 ) {
	continue;
      }
      max = F( A, B );
      
      if( max < min )
	min = max;
    }
  }

  cout << min << endl;
}

int F( int A, int B )
{
  A = checkSize( A );
  B = checkSize( B );

  if( A > B )
    return A;
  else
    return B;
}

int checkSize( int X )
{
  int count = 0;
  
  while( X ) {
    X /= 10;
    count++;
  }
  return count;
}
