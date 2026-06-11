// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n, w; in(n),in(w);
  vector<ll> W(n), V(n);
  loop(i,0,n) in(W[i]),in(V[i]);
  map<ll, int> M;
  loop(i,0,4) M[i+W[0]] = i; // 座標圧縮
  vector<ll> A[4];
  loop(i,0,n) {
    ll a = W[i], v = V[i];
    A[M[a]].push_back(v);
  }
  loop(i,0,4) {
    sort(A[i].rbegin(), A[i].rend());
  }
  vector<ll> acc[4];
  loop(i,0,4) {
    acc[i].push_back(0);
    for (auto &a: A[i]) acc[i].push_back(acc[i].back() + a);
  }
  
  ll ans = 0;
  loop(i,0,A[0].size()+1) {
    loop(j,0,A[1].size()+1) {
      loop(k,0,A[2].size()+1) {
        loop(l,0,A[3].size()+1) {
          if (i*W[0] + j*(W[0]+1) + k*(W[0]+2) + l*(W[0]+3) > w) continue;
          ans = max(ans, acc[0][i] + acc[1][j] + acc[2][k] + acc[3][l]);
        }
      }
    }
  }
  print(ans);
  
  return 0;
}
