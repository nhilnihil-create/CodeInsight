#include <bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> P;
ll X,Y;
/*0 1 2 3 4 5 6
0 x x o o o o o
1 x x x o o o o
2 o x x x o o o
3 o o x x x o o
4 o o o x x x o
5 o o o o x x x
6 o o o o o x x
 */
int main(void)
{
  cin >> X >> Y;
  if(abs(X-Y)<=1)
    {
      cout << "Brown" << endl;
    }
  else
    {
      cout << "Alice" << endl;
    }
  return 0;
}
