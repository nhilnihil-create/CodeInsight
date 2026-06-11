// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

vector<string> S { "dream", "dreamer", "erase", "eraser" };

int main() {
  string t;in(t);
  int n=t.size();
  reverse(t.begin(), t.end());
  loop(i,0,4) reverse(S[i].begin(), S[i].end());
  int idx = 0;
  while (idx < n - 1) {
    bool match = false;
    for (auto &s: S) {
      int size = s.size();
      if (t.substr(idx, size) == s) idx += size,match = true;
    }
    if (!match) {
      print("NO");
      return 0;
    }
  }
  print("YES");
  return 0;
}
