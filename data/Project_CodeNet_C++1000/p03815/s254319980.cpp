#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
  LLI x, ans = 0, mod;
  cin >> x;
  ans += 2 * ( x / 11 );
  ans += ( x - ( x/11 ) * 11 + 5 ) / 6;
  cout << ans;
}