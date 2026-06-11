// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

vector<int> B { 400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 5000 };

int main() {
  int n;in(n);
  vector<int> C(9, 0);
  int a, j;
  loop(i,0,n) {
    in(a);
    j=0;
    while (a >= B[j]) j++;
    C[j]++;
  }
  
  int ans1 = 0;
  loop(i,0,8) ans1 += C[i] > 0;
  int ans2 = ans1 + C[8];
  cout << max(ans1, 1) << " " << ans2 << endl;
  return 0;
}
