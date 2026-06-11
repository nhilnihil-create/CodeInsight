#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,m,R;
    cin >> n >> m >> R;
    vector<int> r(R);
    rep(i,R) {cin >> r[i]; r[i]--;}
    sort(r.begin(), r.end());
    const int INF = INT32_MAX>>3;
    vector<vector<int>> d(n, vector<int>(n,INF));
    rep(i,n) d[i][i] =0;
    rep(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        d[a-1][b-1] = c;
        d[b-1][a-1] = c;
    }
    rep(k,n) rep(i, n) rep(j,n) chmin(d[i][j], d[i][k] + d[k][j]);
    int ans = INF;
    do {
        int d_sum = 0;
        rep(i,R-1) d_sum += d[r[i]][r[i+1]];
        chmin(ans, d_sum);
    } while(next_permutation(r.begin(), r.end()));
    cout << ans << endl;
}