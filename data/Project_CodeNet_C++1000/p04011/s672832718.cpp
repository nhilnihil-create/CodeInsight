#include <iostream>
using namespace std;
int main()
{
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  int sum = 0;
  if( n <= k )
    cout << x * n;
  else{
    cout << x * k + ( n - k ) * y;
  }
}
  