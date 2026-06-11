// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

const int INF = 333333333;

int main() {
  int n, m; in(n),in(m);
  int G[n][n];
  vector<int> A(m),B(m),C(m);
  loop(i,0,n) loop(j,0,n) {
    if (i==j) G[i][j] = 0;
    else G[i][j] = INF;
  }
  loop(i,0,m) {
    int a, b, c; in(a),in(b),in(c);
    a--;b--;
    G[a][b] = G[b][a] = c;
    A[i] = a;
    B[i] = b;
    C[i] = c;
  }
  
  loop(k,0,n)
    loop(i,0,n)
      loop(j,0,n)
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
  
  int cnt = 0;
  loop(i,0,m) {
    cnt += G[A[i]][B[i]] < C[i];
  }
  
  print(cnt);
  return 0;
}
