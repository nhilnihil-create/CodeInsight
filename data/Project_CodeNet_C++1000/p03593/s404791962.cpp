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
  int32 h,w;
  cin >> h >> w;
  vector<int32> cnt(26,0);
  REP(i,h){
    string s;
    cin >> s;
    REP(j,w){
      cnt[s[j] - 'a']++;
    }
  }
  int32 need4,need2,need1;
  if(h % 2 && w % 2){
    need4 = h * w - h - w + 1;
    need2 = h + w - 2;
    need1 = 1;
  }else if(h % 2 || w % 2){
    if(h%2)swap(h,w);
    need4 = h * w - h;
    need2 = h;
    need1 = 0;
  }else{
    need4 = h * w;
    need2 = need1 = 0;
  }
  // cout << need4 << " " << need2 << " " << need1 << endl;
  REP(i,26){
    if(cnt[i] % 2){
      if(need1 > 0){
        cnt[i]--;
        need1--;
      }else{
        Yes(false);
        return 0;
      }
    }
  }
  REP(i,26){
    if(cnt[i] % 4 == 2){
      if(need2 > 0){
        cnt[i] -= 2;
        need2 -= 2;
      }else{
        Yes(false);
        return 0;
      }
    }
  }
  Yes(true);
  return 0;
}