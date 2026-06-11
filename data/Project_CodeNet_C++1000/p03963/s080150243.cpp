// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
#define chmax(x,y) (x = max(x, y))
//  cout.precision(15); cout << fixed;

template<class T1, class T2>
T1 intpow(const T1& a, const T2 n) {
  if (n == 0) return 1;
  auto t = intpow(a, n / 2);
  t = t * t;
  if (n & 1) t = t * a;
  return t;
}

int main() {
  int n, k; cin >> n >> k;
  cout << k * intpow(k-1, n-1) << endl;
  return 0;
}
