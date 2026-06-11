#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int W,H,N;
    cin >> W >> H >> N;
    // true is white
    vector<vector<bool>> v(H,vector<bool>(W, true));
    REP(_,N) {
        int x,y,a;
        cin >> x >> y >> a;
        if (a==1)  REP(i,H)REP (j,x) v[i][j] = false;
        if (a==2)  REP(i,H)FOR (j,x,W) v[i][j] = false;
        if (a==3)  REP(i,y)REP (j,W) v[i][j] = false;
        if (a==4)  FOR(i,y,H)REP (j,W) v[i][j] = false;
    }
    int cnt =  0;
    REP(i,H)REP(j,W) cnt += v[i][j];
    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}
