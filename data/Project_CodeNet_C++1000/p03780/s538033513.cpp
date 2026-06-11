#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,k;
  cin >> n >> k;
  vector<int32> a(n);
  REP(i,n)cin >> a[i];
  sort(ALL(a));
  int32 l=-1,r=n;
  while(r - l > 1){
    int32 mid = (l + r) / 2;
    vector<bool> dp(k,false);
    dp[0] = true;
    REP(i,n){
      if(mid == i)continue;
      FORR(j,k-1-a[i],0){
        if(dp[j])
          dp[j+a[i]] = true;
      }
    }
    bool need = false;
    FOR(i,max<int32>(0,k-a[mid]),k)if(dp[i])need = true;
    if(need){
      r = mid;
    }else{
      l = mid;
    }
  }
  ANS(r);
  return 0;
}