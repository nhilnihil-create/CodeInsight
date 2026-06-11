#include<bits/stdc++.h>
using namespace std;

int main( void )
{
  long long int a, b, x;
  cin >> a >> b >> x;
  long long int count = 0;
 
  cout <<  ( b / x ) - ( ( a + x - 1 ) / x ) + 1;
}
