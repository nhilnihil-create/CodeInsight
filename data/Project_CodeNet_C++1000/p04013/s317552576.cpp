// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

// i枚目まで考慮してk枚選んだ時に合計がsumである場合の数.
ll dp[60][60][3000];
int n, ave;
vector<int> A(50);

ll dfs(int i = 0, int k = 0, ll sum = 0) {
  ll &cc = dp[i][k][sum];
  if (~cc) return cc;
  if (i == n) return cc = k*ave == sum;
  ll ret = 0;
  ret += dfs(i+1, k, sum);
  ret += dfs(i+1, k+1, sum+A[i]);
  return cc = ret;
}


int main() {
  in(n),in(ave);
  loop(i,0,n) in(A[i]);
  memset(dp, -1, sizeof(dp));
  
  print(dfs()-1);
  return 0;
}
