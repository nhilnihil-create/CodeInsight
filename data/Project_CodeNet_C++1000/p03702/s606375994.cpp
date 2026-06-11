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

    llong n, a, b;
    cin >> n >> a >> b;
    llong h_max = -1;
    vector<llong> h(n);
    rep(i, n) {
        cin >> h[i];
        h_max = max(h_max, h[i]);
    }

    llong left = 0, right = (h_max / b) + 1, t;
    while (left + 1 < right) {
        t = (left + right) / 2;
        llong cnt = 0;
        rep(i, n) {
            if (h[i] > b * t) cnt += ceil((ldouble)(h[i] - b * t) / (a - b));
        }
        if (cnt <= t) right = t;
        else left = t;
    }

    cout << right << endl;

    return 0;
}