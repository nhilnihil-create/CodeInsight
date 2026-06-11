#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<bool, int>> box(N);
    box[0] = make_pair(true, 1);
    rep2(i,1, N) {
        box[i] = make_pair(false, 1);
    }
    int ans = 0;
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (!box[x].first) {
            box[x].second--;
            box[y].second++;
            continue;
        }
        if (box[x].second == 1) {
            box[x].first = false;
            box[y].first = true;
            box[x].second--;
            box[y].second++;
            continue;
        }
        box[x].second--;
        box[y].first = true;
        box[y].second++;
    }
    rep(i, N) {
        if (box[i].first) {
            ans++;
        }
    }
    cout << ans << endl;
}