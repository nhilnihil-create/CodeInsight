// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  ll n; cin >> n;
  int min_ = 10000000;
  for (ll x = 1; x*x<=n; x++) {
    if (n%x!=0) continue;
    int a = to_string(x).size();
    int b = to_string(n/x).size();
    int c = max(a, b);
    if (min_ > c) {
      min_ = c;
    }
  }
  cout << min_ << endl;
  return 0;
}
