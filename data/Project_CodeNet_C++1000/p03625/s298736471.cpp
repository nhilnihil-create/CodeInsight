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
  map<ll, ll> M;
  for (auto&& a: A) M[a]++;
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  n = A.size();
  reverse(A.begin(), A.end());
  ll prev = -1;
  ll max_ = 0;
  for (auto &&a: A) {
    if (M[a] <= 1) continue;
    if (M[a] >= 4) {
      max_ = max(max_, a*a);
    }
    max_ = max(max_, prev*a);
    prev = a;
  }
  cout << max_ << endl;
  return 0;
}
