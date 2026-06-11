#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, K;
  cin >> N >> K;

  long long int ans = 1;
    
  ans = K;
  
  if( N != 1 )
    for( int i = 0; i < N - 1; i++ )
	ans *= ( K - 1 );

  cout << ans << endl;
}