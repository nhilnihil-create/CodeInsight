#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

ll min_price = INF;

void dfs2(ll i, ll S, ll D, double n, ll sum) {
    double lit = 2.0 / pow(2, (i-1));

    if (min_price < sum) {
        // cout << "END." << endl;
        return;
    }

    if (i == 2) {
        sum += n * S;
        // cout << "RESULT: " << sum << endl;
        if (min_price > sum) {
            // cout << "UPDATE: " << sum << endl;
            min_price = sum;
        }
        return;
    }

    ll max_select = n / lit;
    // cout << "max_select:" << max_select << endl;

    for (int k = 0; k <= max_select; k++) {
        if (i == 1) {
            dfs2(i+1, S, D, n-lit*k, sum + k*D);
        }
        // } else if (i == 2) {
        //     dfs(i+1, S, D, n-lit*k, sum + k*S);
        // } else if (i == 3) {
        //     dfs(i+1, Q, H, S, D, n-lit*k, sum + k*H);
        // }
    }
}

int main() {
    ll Q, H, S, D;
    cin >> Q >> H >> S >> D;

    // double N;
    ll N;
    cin >> N;

    H = min(H, 2*Q);
    S = min(S, 2*H);

    ll ans;
    if (2 * S < D) {
        ans = N * S;
    } else {
        ans = (N / 2) * D + (N % 2) * S;
    }

    cout << ans << endl;

    // dfs2(1, S, D, N, 0);
    // cout << min_price << endl;

    return 0;
}