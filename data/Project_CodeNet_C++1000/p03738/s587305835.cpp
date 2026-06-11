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
    string a,b;
    cin >> a >> b;
    if(a.size() > b.size()){
        ANS("GREATER");
        return 0;
    }else if(a.size() < b.size()){
        ANS("LESS");
        return 0;
    }else{
        REP(i,a.size()){
            if(a[i] == b[i])continue;
            if(a[i] > b[i]){
                ANS("GREATER");
            }else if(a[i] < b[i]){
                ANS("LESS");
            }
            return 0;
        }
    }
    ANS("EQUAL");
    return 0;
}