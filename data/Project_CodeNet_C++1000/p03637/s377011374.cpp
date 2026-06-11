// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

// 隣り合う要素の積をすべて4の倍数に出来るか.
// まず4を因数にもつ合成数xの前後はok.
// 2を因数にもつ整数yは２つ隣り合う必要がある.
int main() {
  int n;in(n);
  vector<ll> A(n);
  loop(i,0,n) in(A[i]);
  int cnt4 = 0;
  int cnt2 = 0;
  for (auto &&a: A) {
    if (a%4==0) cnt4++;
    else if (a%2 == 0) cnt2++;
  }
  int cnt = n-(cnt2/2)*2; // ｙを2つペアにして消去.
  if (cnt <= cnt4*2 + 1) print("Yes");
  else print("No");
  return 0;
}
