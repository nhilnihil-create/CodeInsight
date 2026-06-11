#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, K;
  cin >> N >> K;
  vector<int> l( N );
  int sum = 0;

  for( int i = 0; i < N; i++ )
    cin >> l.at( i );

  sort( l.begin(), l.end(), greater<int>() );

  for( int i = 0; i < K; i++ )
    sum += l.at( i );

  cout << sum << endl;
}