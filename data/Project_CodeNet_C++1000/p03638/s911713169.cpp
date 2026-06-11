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
    int32 h,w;
    cin >> h >> w;
    vector<vector<int32>> ans(h, vector<int32>(w, -1));
    int32 x = 0;
    int32 y = 0;
    int32 n;
    cin >> n;
    FOR(i,1,n+1){
        int32 a;
        cin >> a;
        REP(j,a){
            ans[x][y] = i;
            if(x % 2 == 0){
                if(y == w - 1){
                    x++;
                }else{
                    y++;
                }
            }else{
                if(y == 0){
                    x++;
                }else{
                    y--;
                }
            }
        }
    }
    REP(i,h){
        REP(j,w){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}