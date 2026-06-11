// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<int, int> P;

int main() {
  ll n, t; cin >> n >> t;
  vector<ll> A(n);
  loop(i,0,n) cin >> A[i];
  ll cur = -1; 
  ll total = 0;
  for (auto start: A) {
    ll end = start + t;
    if (cur < start) total += t;
    else if (cur < end) total += end-cur;
    cur = max(cur, end);
  }
  cout << total << endl;
  return 0;
}
