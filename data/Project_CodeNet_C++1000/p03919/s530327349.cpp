#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define int long long
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e18 * 5;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<string> > s(H, vector<string>(W));
    REP(i, H)REP(j, W) cin >> s[i][j];
    REP(i, H){
        REP(j, W){
            if(s[i][j] == "snuke"){
                cout << (char)('A'+j) << i+1 << "\n";
                return 0;
            }
        }
    }
    return 0;
}