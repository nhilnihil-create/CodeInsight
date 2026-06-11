// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<ll, ll> P;

int main() {
  int n, m; in(n),in(m);
  vector<P> A(n),B(m);
  loop(i,0,n) in(A[i].first),in(A[i].second);
  loop(i,0,m) in(B[i].first),in(B[i].second);
  loop(i,0,n) {
    ll x = A[i].first, y = A[i].second;
    int k = -1;
    ll min_ = 100000000000000000;
    loop(j,0,m) {
      ll x_ = B[j].first, y_ = B[j].second;
      ll d = abs(x-x_) + abs(y-y_);
      if (min_ > d) {
        min_ = d;
        k = j;
      }
    }
    print(k+1);
  }
  
  return 0;
}
