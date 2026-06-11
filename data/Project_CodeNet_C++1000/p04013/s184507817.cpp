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
int main() {
  int n, ave; in(n),in(ave);
  vector<int> A(n);
  loop(i,0,n) in(A[i]);
  dp[0][0][0] = 1;
  loop(i,0,n) {
    int a = A[i];
    loop(k,0,n) {
      loop(sum,0,3000) {
        if (dp[i][k][sum]==0) continue;
        dp[i+1][k][sum] += dp[i][k][sum];
        dp[i+1][k+1][sum+a] += dp[i][k][sum];
      }
    }
  }
  
  ll ans = 0;
  loop(k,1,n+1) {
    ans += dp[n][k][k*ave];
  }
  print(ans);
  return 0;
}
