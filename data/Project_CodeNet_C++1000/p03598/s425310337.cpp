// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

int main() {
  int n, k; cin >> n >> k;
  vector<int> X(n);
  loop(i,0,n) cin >> X[i];
  int t = 0;
  loop(i,0,n) {
    t += 2 * min(X[i], abs(k-X[i]));
  }
  cout << t << endl;
  return 0;
}
