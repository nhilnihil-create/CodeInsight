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
  int32 n;
  cin >> n;
  vector<int32> a(3*n);
  REP(i,3*n)cin >> a[i];
  vector<int32> frt(n+1),bck(n+1);

  priority_queue<int32,vector<int32>,greater<int32>> p;
  REP(_,2){  
    int64 sum = 0;
    REP(i,n){
      sum += a[i];
      p.push(a[i]);
    }
    frt[0]=sum;
    REP(i,n){
      sum += a[n+i];
      p.push(a[n+i]);
      sum -= p.top();
      p.pop();
      frt[i+1] = sum;
    }

    swap(frt,bck);
    reverse(ALL(a));
    REP(i,3*n)a[i] *= -1;
  }
  // REP(i,n+1)cout << frt[i] << " ";
  // cout << endl;
  // REP(i,n+1)cout << bck[i] << " ";
  // cout << endl;
  int64 ans = -LLINF;
  REP(i,n+1)ans = max(ans, frt[i] + bck[n-i]);
  ANS(ans);
  return 0;
}