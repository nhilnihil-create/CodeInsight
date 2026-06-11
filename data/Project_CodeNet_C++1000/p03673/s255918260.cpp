// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n; cin >> n;
  vector<ll> A(n);
  list<ll> B;
  loop(i,0,n) cin >> A[i];
  loop(i,0,n) {
    if (i%2==0) {
      B.push_back(A[i]);
    } else {
      B.push_front(A[i]);
    }
  }
  if (n%2==1) {
    reverse(B.begin(), B.end());
  }
  for (auto it = B.begin(); it != B.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
