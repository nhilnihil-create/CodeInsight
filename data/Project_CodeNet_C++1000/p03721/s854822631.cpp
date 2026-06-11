// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n, k; cin >> n >> k;
  k--;
  vector<pair<ll, ll> > A;
  loop(i,0,n) {
    ll a, b; cin >> a >> b;
    A.emplace_back(a, b);
  }
  sort(A.begin(), A.end());
  ll sum = 0;
  for (auto a: A) {
    if (sum + a.second > k) {
      cout << a.first << endl;
      return 0;
    }
    
    sum += a.second;
  }
  cout << A[A.size()-1].first << endl;
  return 0;
}
