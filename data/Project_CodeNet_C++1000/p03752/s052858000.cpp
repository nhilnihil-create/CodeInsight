#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

template <typename T> T &chmin(T &a, const T &b) {return a = min(a, b);}
template <typename T> T &chmax(T &a, const T &b) {return a = max(a, b);}

using ll = long long;
using ld = long double;

const int INF = 1e9;
const ld eps = 1e-9, pi = acos(-1.0);

int main(){
  int n, k;
  cin >> n >> k;
  int a[15];
  REP(i, n) cin >> a[i];
  ll res = 1e11;
  REP(i, 1<<n){
    ll tmpres = 0;
    bitset<15> target(i);
    if(target.count()!=k) continue;
    int required = 0;
    REP(j, n) {
      if(target[j]) tmpres += max(0, required-a[j]+1);
      chmax(required, max(a[j], required+target[j]));
    }
    chmin(res, tmpres);
  }
  cout << res << endl;
  return 0;
}