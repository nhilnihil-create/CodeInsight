// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

typedef pair<ll, ll> P;

int main() {
  int n, k; cin >> n >> k;
  vector<int> A(n); loop(i,0,n) cin >> A[i];
  sort(A.rbegin(), A.rend());
  int total = 0;
  loop(i,0,min(k,n)) total += A[i];
  cout << total << endl;
  return 0;
}
