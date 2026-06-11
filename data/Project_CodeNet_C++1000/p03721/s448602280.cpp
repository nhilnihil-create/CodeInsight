// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n, k; cin >> n >> k;
  map<ll, ll> M;
  loop(i,0,n) {
    ll a, b; cin >> a >> b;
    M[a] += b;
  }
  
  ll sum = 0;
  for (auto m: M) {
    sum += m.second;
    if (sum >= k) {
      cout << m.first << endl;
      return 0;
    }
  }
  return 0;
}
