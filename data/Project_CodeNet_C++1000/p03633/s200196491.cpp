// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n;
  cin >> n;
  vector<ll> A(n);
  loop(i,0,n) cin >> A[i];
  ll l = 1;
  loop(i,0,n) l = lcm(l, A[i]);
  cout << l << endl;
  return 0;
}
