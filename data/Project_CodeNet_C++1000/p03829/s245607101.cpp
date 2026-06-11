// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  ll n, a, b; cin >> n >> a >> b;
  vector<ll> X(n), D;
  loop(i,0,n) cin >> X[i];
  loop(i,0,n-1) D.push_back(X[i+1]-X[i]);
  ll sum = 0;
  for (auto&&d: D) sum += min(d*a, b);
  cout << sum << endl;
  return 0;
}
