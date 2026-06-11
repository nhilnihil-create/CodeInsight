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
  for (auto &&a: A) {
    M[a-1]++;
    M[a]++;
    M[a+1]++;
  }
  ll max_ = 0;
  for (auto &&m: M) {
    if (max_ < m.second) {
      max_ = m.second;
    }
  }
  cout << max_ << endl;
  return 0;
}
