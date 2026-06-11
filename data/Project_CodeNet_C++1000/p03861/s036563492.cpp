// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
 * 0 1 2 3 4 5 6 7 8
 * o   o   o   o   o
 * x   x
 * 
 */
int main() {
  ll a, b, x; cin >> a >> b >> x;
  ll n = b/x + 1;
  if (a==0) {
    cout << n << endl;
    return 0;
  }
  a--;
  n -= a/x + 1;
  cout << n << endl;
  return 0;
}
