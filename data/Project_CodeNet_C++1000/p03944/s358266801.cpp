// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int w, h, n; in(w),in(h),in(n);
  vector<int> X(n),Y(n),A(n);
  loop(i,0,n) in(X[i]),in(Y[i]),in(A[i]);
  int min_x = 0, max_x = w, min_y = 0, max_y = h;
  loop(i,0,n) {
    int a = A[i];
    if (a==1) min_x = max(min_x, X[i]);
    if (a==2) max_x = min(max_x, X[i]);
    if (a==3) min_y = max(min_y, Y[i]);
    if (a==4) max_y = min(max_y, Y[i]);
  }
  print(max(0, max_x-min_x) * max(0, max_y-min_y));
  return 0;
}
