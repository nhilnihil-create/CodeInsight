#include <bits/stdc++.h>
#define INF 1e9
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define FORE(i, a, b) for (int i = (a), e = (b); i < e; ++i)
#define RFORE(i, a, b) for (int i = (b)-1, e = (a); i >= e; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(c) sort((c).begin(), (c).end())
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    ll ans1   = 0;
    ll ans2   = 0;
    ll mysum1 = 0;
    ll mysum2 = 0;
    // aは変更しない 変更するのは累積和のみ
    // 正負正負
    FOR(i, 0, N) {
        mysum1 += a.at(i);
        // 累積和が正であるべきところが負なら 1になるようにする
        if ((i % 2 == 0) & (mysum1 <= 0)) {
            ans1 += abs(mysum1) + 1;
            mysum1 = 1;
        } else if ((i % 2 == 1) & (mysum1 >= 0)) {
            ans1 += abs(mysum1) + 1;
            mysum1 = -1;
        }
    }
    // 負正負正
    FOR(i, 0, N) {
        mysum2 += a.at(i);
        // 累積和が正であるべきところが負なら 1になるようにする
        if ((i % 2 == 1) & (mysum2 <= 0)) {
            ans2 += abs(mysum2) + 1;
            mysum2 = 1;
        } else if ((i % 2 == 0) & (mysum2 >= 0)) {
            ans2 += abs(mysum2) + 1;
            mysum2 = -1;
        }
    }
    cout << min(ans1, ans2) << endl;
}
