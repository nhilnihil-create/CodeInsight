#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1E+18;

int main() {
    int N, K;
    cin >> N >> K;

    int A[N];
    rep(i, N) cin >> A[i];

    ll ans = INF;
    for (int bit=1; bit < (1<<N); bit++) {
        if (__builtin_popcount(bit) != K) continue;
        int front_highest = 0;
        ll cost = 0;
        rep(i, N) {
            if (bit & (1<<i)) {
                cost += max(front_highest - A[i] + 1, 0);
                front_highest++;
            }
            front_highest = max(front_highest, A[i]);
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}