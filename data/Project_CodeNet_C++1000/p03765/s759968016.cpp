#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int32 n = s.size();
  int32 m = t.size();
  vector<int64> scnt(n+1,0);
  vector<int64> tcnt(m+1,0);
  REP(i,n){
    scnt[i+1] = scnt[i];
    if(s[i] == 'A')scnt[i+1]++;
  }
  REP(i,m){
    tcnt[i+1] = tcnt[i];
    if(t[i] == 'A')tcnt[i+1]++;
  }
  int32 q;
  cin >> q;
  while(q--){
    int32 a,b,c,d;
    cin >> a >> b >> c >> d;
    int32 cura = scnt[b] - scnt[a-1];
    int32 curb = b - a + 1 - cura;
    int32 tara = tcnt[d] - tcnt[c-1];
    int32 tarb = d - c + 1 - tara;
    if(((cura - tara) * 2 - (tarb - curb)) % 3 == 0){
      cout << "YES\n";
    }else{
      cout << "NO\n";
    }
  }
  return 0;
}