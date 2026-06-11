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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n;
  string s;
  cin >> n >> s;
  REP(j,4){
    // int32 ans = j;
    vector<bool> wolf(n,false);
    REP(i,2)if(j>>i&1)wolf[i] = true;
    FOR(i,2,n){
      if(s[i-1] == 'o'){
        // ans |= ((ans>>(i-2)&1) ^ (ans>>(i-1)&1)) << i;
        wolf[i] = wolf[i-2] != wolf[i-1];
      }else{
        // ans |= ((ans>>(i-2)&1) ^ (ans>>(i-1)&1) ^ 1) << i;
        wolf[i] = wolf[i-2] == wolf[i-1];
      }
    }
    // if(s[n-2] == 'o' && (ans>>(n-3)&1) ^ (ans>>(n-2)&1) ^ (ans>>(n-1)&1))continue;
    if(s[n-2] == 'o' && (wolf[n-3] != wolf[n-2]) != wolf[n-1])continue;
    // if(s[n-2] == 'x' && (ans>>(n-3)&1) ^ (ans>>(n-2)&1) ^ (ans>>(n-1)&1) ^ 1)continue;
    if(s[n-2] == 'x' && (wolf[n-3] != wolf[n-2]) == wolf[n-1])continue;
    // if(s[n-1] == 'o' && (ans>>(n-2)&1) ^ (ans>>(n-1)&1) ^ (ans&1))continue;
    if(s[n-1] == 'o' && (wolf[n-2] != wolf[n-1]) != wolf[0])continue;
    // if(s[n-1] == 'x' && (ans>>(n-2)&1) ^ (ans>>(n-1)&1) ^ (ans&1) ^ 1)continue;
    if(s[n-1] == 'x' && (wolf[n-2] != wolf[n-1]) == wolf[0])continue;
    // cout << bitset<6>(ans) << endl;
    if(s[0] == 'o' && (wolf[n-1] != wolf[0]) != wolf[1])continue;
    if(s[0] == 'x' && (wolf[n-1] != wolf[0]) == wolf[1])continue;
    REP(i,n){
      if(wolf[i]){
        cout << 'W';
      }else{
        cout << 'S';
      }
    }
    cout << endl;
    return 0;
  }
  ANS(-1);
  return 0;
}