#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
typedef long long llint;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 999999999;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    map<P, int> m;

    int H, W, N;
    cin >> H >> W >> N;
    REP(i, N){
        int a, b;
        cin >> a >> b;
        FOR(j, a-1, a+2)FOR(k, b-1, b+2){
            if(m.find(mp(j,k)) == m.end()) m[mp(j, k)] = 1;
            else m[mp(j, k)]++;
        }
    }
    vector<llint> ans(10,0);
    for(auto x : m){
        P key = x.first;
        if(key.first <= 1 || key.first >= H) continue;
        if(key.second <= 1 || key.second >= W) continue;

        ans[m[key]]++;
    }

    ans[0] = (llint)(H-2)*(W-2);
    FOR(i, 1, 10) ans[0] -= ans[i];
    REP(i, 10) cout << ans[i] << "\n";
    return 0;
}