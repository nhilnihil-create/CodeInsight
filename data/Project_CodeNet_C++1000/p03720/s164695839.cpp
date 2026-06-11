#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int N, M, A, B;
  cin >> N >> M;
  
  vector<int> ans( N );

  for( int i = 0; i < M; i++ ) {
    cin >> A >> B;
    ans.at( A - 1 )++;
    ans.at( B - 1 )++;
  }

 for( int i = 0; i < N; i++ )
   cout << ans.at( i ) << endl;
}