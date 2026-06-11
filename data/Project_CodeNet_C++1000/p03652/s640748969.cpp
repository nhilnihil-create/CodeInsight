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

int32 n,m;
vector<vector<int32>> a;

int32 cntmax(){
    vector<pii> cnt(m);
    REP(i,m)cnt[i] = pii(0, i);
    REP(i, n){
        cnt[a[i][0]].first++;;
    }
    sort(ALL(cnt), greater<pii>());
    REP(i,n){
        a[i].erase(find(ALL(a[i]), cnt[0].second));
    }
    // cout << cnt[0].first << " " << cnt[0].second + 1 << endl;
    return cnt[0].first;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    a = vector<vector<int32>>(n, vector<int32>(m));
    REP(i,n)REP(j,m){
        cin >> a[i][j];
        a[i][j]--;
    }
    int32 ans = INF;
    REP(i,m){
        int32 mx = cntmax();
        ans = min(ans, mx);
    }
    ANS(ans);
    // ostream_iterator<int32> out_it(cout, " ");
    // copy(ALL(a[0]), out_it);
    return 0;
}