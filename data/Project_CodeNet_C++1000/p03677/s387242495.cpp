#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    REP(i, n) {
        cin >> a[i];
        --a[i];
    }

    function<int(int, int)> dist = [&](int x, int y) {
        return x > y ? m - x + y : y - x;
    };

    map<int, int> n_begin, n_end;
    map<int, ll> lose;
    ll initial_cost = 0;
    ll cut = 0;
    int count = 0;

    REP(i, n - 1) {
        ++n_begin[a[i]];
        ++n_end[a[i + 1]];
        if (a[i] > a[i + 1]) {
            cut += (m - a[i]) - 1;
            ++count;
        }
        initial_cost += dist(a[i], a[i + 1]);
        lose[a[i + 1]] += dist(a[i], a[i + 1]);
    }

    ll cut_max = cut;

    REP(i, m - 1) {
        count -= n_end[i];
        cut += -lose[i] + n_end[i];

        count += n_begin[i];
        cut += count - n_begin[i];

        cut_max = max(cut_max, cut);
    }

    ll result = initial_cost - cut_max;

    cout << result << endl;

    return 0;
}
