#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const int MAX = 205;
/* global variables */
/* function */
/* main */
int main(){
    ll N, M, R, a, b, c;
    cin >> N >> M >> R;
    vector<ll> r(R);
    sort(r.begin(), r.end());
    for (int i = 0; i < R; i++) {cin >> r[i]; r[i]--;}
    vector<vector<ll> > d(MAX, vector<ll>(MAX, INF));
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c; d[b][a] = c;
    }

    for (int i = 0; i < MAX; i++) d[i][i] = 0;
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            if (d[i][k] == INF) continue;
            for (int j = 0; j < MAX; j++) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    sort(r.begin(), r.end());
    ll ans = INF;
    do {
        ll tmp = 0;
        for (int i = 0; i < R - 1; i++) { tmp += d[r[i]][r[i+1]]; }
        ans = min(ans, tmp);
    } while(next_permutation(r.begin(), r.end()));

    cout << ans << '\n';
}