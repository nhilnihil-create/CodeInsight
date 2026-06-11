#include <bits/stdc++.h>
using namespace std;

# define rep(i, n) for(int(i)=0;(i)<(n);(i)++)
# define reps(i, n) for(int(i)=1;(i)<=(n);(i)++)
# define rrep(i, n) for(int i=((int)(n)); i>0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>=0; --i)
# define ALL(v) v.begin(), v.end()
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<typename T> void dump(T e){std::cout << e << std::endl;}
template<typename T> void dump(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void dump(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ dump(v); } }
typedef long long ll;

int main() {
  int N; cin >> N;
  vector<int> A(N); rep(i, N) cin >> A[i];
  int ans=1;
  int d=0,tmp;
  reps(i, N-1) {
    tmp = A[i] - A[i-1];
    if(tmp==0) continue;
    tmp = tmp > 0? 1:-1;
    if (d==0) {
      d = tmp;
    } else if(d!=tmp) {
      d=0;
      ans++;
    }
  }
  dump(ans);
}
