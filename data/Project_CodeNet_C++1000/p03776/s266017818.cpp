#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

ll com[51][51];

int main() {
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];
        }
    }

    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    rep(i, N) cin >> v[i];
    sort(v.rbegin(), v.rend());

    double avg = 0;
    rep(i, A) avg += v[i];
    avg /= A;

    int cnt = 0; // 平均値に使用される数字の中で一番小さい数字の個数
    rep(i, N) if (v[i] == v[A - 1]) cnt++;
    ll ans = 0;
    if (v[0] == v[A - 1]) { // 平均値に使用される数値がすべて同じ場合
        for (int i = A; i <= B; i++) {
            if (cnt < i) break; // cnt個以上は選べない
            ans += com[cnt][i]; // cnt個から平均値に使用される数値をi個選ぶ
        }
    } else {
        int cnt2 = 0;
        rep(i, A) if (v[i] == v[A - 1]) cnt2++;
        ans = com[cnt][cnt2]; // 平均値に使用される一番小さい数字が数列中にcnt個あり、その中のcnt2個を平均値の計算に採用する
    }

    cout << fixed << setprecision(10) << avg << endl;
    cout << ans << endl;
}