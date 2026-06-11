// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  string s; in(s);
  int n = s.size();
  int p = 0;
  loop(i,0,n) p += s[i] == 'p';
  // nが偶数の時n/2
  // nが奇数ｎ時n/2 (切り捨て)
  print(n/2 - p);
  return 0;
}
