#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define ternary(condition, x, y) ((condition) ? x : y) 
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static llong MOD = 1000000000 + 7;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

int main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    llong sub_ans_x = 0;
    for (int i = 1; i <= n; ++i) {
        llong x;
        cin >> x;
        sub_ans_x += (i - 1) * x - (n - i) * x;
        sub_ans_x %= MOD;
    }

    llong sub_ans_y = 0;
    for (int i = 1; i <= m; ++i) {
        llong y;
        cin >> y;
        sub_ans_y += (i - 1) * y - (m - i) * y;
    }

    llong ans = (sub_ans_x % MOD) * (sub_ans_y % MOD);

    cout << ans % MOD << endl;

    return 0;
}