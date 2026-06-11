#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll Q, H, S, D, N;
int main() {
    cin >> Q >> H >> S >> D >> N;
    vector<P> calc(4);
    calc[0] = P(8 * Q, 0); 
    calc[1] = P(4 * H, 1); 
    calc[2] = P(2 * S, 2); 
    calc[3] = P(D, 3); 

    ll ans = INF;
    // for (int i = 1; i < 1 << 4; i++) {
    for (int i = 15; i < 1 << 4; i++) {
        vector<ll> target;
        for (int j = 0; j < 4; j++) {
            if (i >> j & 1) {
                target.push_back(j);
                // cout << j << " ";
            }
        }
        // 2l の時のみ、偶数しか作れない
        if (target.size() == 1 && target[0] == 3 && N % 2 == 1) continue;

        // 1l あたりの金額を計算
        vector<P> tmp;
        ll tmp_ans = 0;
        rep(k, target.size()) {
            tmp.push_back(calc[target[k]]);
        }
        sort(tmp.begin(), tmp.end());

        // 2lの場合 0こめを使う
        if (N % 2 == 0) {
            tmp_ans += (N / 2) * tmp[0].first;
        } else {
            tmp_ans += ((N - 1) / 2) * tmp[0].first;

            // 最後の1lをどうするか
            if (tmp[0].second == 3) {
                if (tmp.size() == 1) continue;
                tmp_ans += tmp[1].first / 2;
            } else {
                tmp_ans += tmp[0].first / 2;
            }
        }
        ans = min(ans, tmp_ans);
        // rep(k2, tmp.size()) {
        //     cout << tmp[k2].first << " " << tmp[k2].second << endl;
        // }
    }
    cout << ans << endl;
}