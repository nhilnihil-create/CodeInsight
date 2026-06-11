#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int N, M, R;
int r[10];
int d[210][210];

signed main() {
    cin >> N >> M >> R;
    rep(i, R) cin >> r[i];
    rep(i, R) r[i]--;
    rep(i, N) rep(j, N) d[i][j] = 1000000000;
    rep(i, N) d[i][i] = 0;
    rep(i, M) {
        int A, B, C; cin >> A >> B >> C;
        d[A-1][B-1] = C;
        d[B-1][A-1] = C;
    }
    
    rep(k, N) rep(i, N) rep(j, N) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    int ans = 1000000000;
    vector<int> l;
    rep(i, R) l.pb(i);
    
    do {
        int ans_cand = 0;
        rep(i, R-1) {
            int now = r[l[i]], nex = r[l[i+1]];
            ans_cand += d[now][nex];
        }
        ans = min(ans, ans_cand);
    } while (next_permutation(l.begin(), l.end()));
    cout << ans << endl;
}