// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n;in(n);
  vector<ll> A(n);
  loop(i,0,n) in(A[i]);
  map<ll, int> M;
  loop(i,0,n) {
    M[A[i]]++;
  }
  
  ll ans = 0;
  ll max_ = 0;
  for (auto&&m: M) {
    if (m.second >= 4) ans = max(ans, m.first*m.first);
    else if (m.second >= 2) {
      ans = max(ans, m.first*max_);
    }
    if (m.second >= 2) max_ = max(max_, m.first);
  }
  print(ans);
  return 0;
}
