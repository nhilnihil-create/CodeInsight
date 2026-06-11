#include <bits/stdc++.h>
using namespace std;

typedef int_fast32_t int32;
typedef int_fast64_t int64;

const int32 inf = 1e9+7;
const int32 MOD = 1000000007;
const int64 llinf = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define all(obj) (obj).begin(),(obj).end()
#define rall(obj) (obj).rbegin(),(obj).rend()
#define fi first
#define se second
#define pb(a) push_back(a)
typedef pair<int32,int32> pii;
typedef pair<int64,int64> pll;

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return true; } return false;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; } return false;
}

int64 sum(int32 x){
  return (int64)(1+x) * x / 2;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n;
  cin >> n;
  vector<int32> a(n);
  int64 asum = 0;
  REP(i,n){
    cin >> a[i];
    asum += a[i];
  }
  if(asum % sum(n) != 0){
    YES(false);
    return 0;
  }
  int64 m = asum / sum(n);
  vector<int32> d(n);
  REP(i,n)d[i] = a[(i+1)%n] - a[i];
  REP(i,n)d[i] -= m;
  bool flg = true;
  REP(i,n){
    if(d[i] > 0 || d[i] % n)flg = false;
  }
  YES(flg);
  return 0;
}