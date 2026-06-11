#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int N, M;
int A[333][333];
int ng[333];

// もっとも多くの人が参加するスポーツとそのスポーツに参加する人数を調べる
// その後、そのスポーツを候補から除外する
int solve() {
    vector<int> cnt(M);
    rep(i, 0, N) {
        rep(j, 0, M) {
            if(ng[A[i][j]]) continue;
            cnt[A[i][j]]++;
            break;
        }
    }
    int mx = 0;
    int sp = 0;
    rep(i, 0, M) {
        if(mx < cnt[i]) {
            mx = cnt[i];
            sp = i;
        }
    }
    ng[sp] = 1;
    return mx;
}

int main() {
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) {
        cin >> A[i][j];
        A[i][j]--;
    }
    int ans = N;
    rep(i, 0, M) ans = min(ans, solve());
    cout << ans << endl;
    return 0;
}
