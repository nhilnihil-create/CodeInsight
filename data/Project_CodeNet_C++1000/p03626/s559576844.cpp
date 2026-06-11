// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
3色.
|
|
--
--
1 2
---
2 1
2 3
3 1

*/
const ll MOD = 1000000007;
int main() {
  int n;in(n);
  string s, t;in(s),in(t);
  int i = 0;
  ll ans = 1;
  int prev = -1; // -1 None, 0 |, 1 --
  while (i < n) {
    if (s[i] == t[i]) {
      if (prev == -1) {
        ans *= 3;
      } else if (prev == 0) {
        ans *= 2; ans %= MOD;
      } else {
        // ans *= 1;
      }
      prev = 0;
      i++;
      continue;
    }
    
    if (prev == -1) {
      ans *= 6;
    } else if (prev == 0) {
      ans *= 2; ans %= MOD;
    } else {
      ans *= 3; ans %= MOD;
    }
    prev = 1;
    i += 2;
  }
  print(ans);
  return 0;
}
