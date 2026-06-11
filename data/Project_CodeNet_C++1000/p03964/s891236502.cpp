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
  vector<ll> S(n), T(n);
  loop(i,0,n) in(S[i]),in(T[i]);
  ll s = 1, t = 1;
  loop(i,0,n) {
    ll x = max(s/S[i] + (s%S[i]!=0), t/T[i] + (t%T[i]!=0));
    s = x * S[i], t = x * T[i];
  }
  print(s+t);
  return 0;
}
