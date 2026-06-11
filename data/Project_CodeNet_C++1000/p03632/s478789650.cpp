#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int ans = 0;
  
  if( C <= B && B <= D )
    ans = B - C;
  if( C <= A && A <= D )
    ans = D - A;
  if( C <= A && B <= D )
    ans = B - A;
  if( A <= C && D <= B )
    ans = D - C;

  cout << ans << endl;
}