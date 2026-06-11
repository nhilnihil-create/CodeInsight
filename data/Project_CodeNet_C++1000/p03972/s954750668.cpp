#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

using ll = long long;
using P = pair<ll, int>;    // (重み, 縦横)

int main() {
    int W, H;
    cin >> W >> H;

    const int MAXN = 200000;
    static P elts[MAXN];

    for (int i = 0; i < W; i++) {
        cin >> elts[i].first;
        elts[i].second = 0;
    }
    for (int i = 0; i < H; i++) {
        cin >> elts[W + i].first;
        elts[W + i].second = 1;
    }

    int N = W + H;
    sort(elts, elts + N);

    ll counter[2] = {W + 1, H + 1};
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        P& p = elts[i];

        ans += p.first * counter[p.second ^ 1];
        counter[p.second]--;
    }
    cout << ans << endl;

    return 0;
}