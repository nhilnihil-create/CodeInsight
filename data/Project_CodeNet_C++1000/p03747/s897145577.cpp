#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

Int INF = 1e18;
Int mod = 1e9+7;
//Int mod = 998244353;

int main() {
    Int n, l, t;
    cin >> n >> l >> t;
    vector<Int> x(n), w(n);
    for (Int i = 0; i < n; i++) {
        cin >> x[i] >> w[i];
    }
    vector<Int> ox = x;
    bool check = true;
    for (Int i = 0; i < n; i++) {
        if (w[i] != w[(i + 1) % n]) check = false;
    }
    if (check) {
        Int d = t % l;
        for (Int i = 0; i < n; i++) {
            if (w[0] == 1) {
                dump((x[i] + d) % l);
            }
            else {
                dump((x[i] - d + l) % l);
            }
        }
        return 0;
    }
    Int index = -1;
    for (Int i = 0; i < n; i++) {
        if (w[i] == 1) {
            index = i;
            break;
        }
    }
    Int cnt = 0;
    for (Int i = 0; i < n; i++) {
        if (w[i] == 2) {
            cnt++;
        }
    }
    Int rnum = cnt * ((Int)2 * t / l);
    Int r = 2 * t % l;
    for (Int i = index + 1; i < n; i++) {
        if (w[i] == 2) {
            if (x[i] - x[index] < r) {
                rnum++;
            }
        }
    }
    for (Int i = 0; i < index; i++) {
        if (w[i] == 2) {
            if (x[i] + (l - x[index]) < r) {
                rnum++;
            }
        }
    }
    rnum %= n;
    Int xx = (x[index] + t) % l;
    vector<Int> res(n);
    for (Int i = 0; i < n; i++) {
        if (w[i] == 1) {
            res[i] = (x[i] + t) % l;
        }
        else {
            res[i] = (x[i] - (t % l) + l) % l;
        }
    }
    sort(all(res));
    Int new_index = -1;
    for (Int i = 0; i < n; i++) {
        if (res[i] == xx) {
            new_index = i;
            break;
        }
    }
    new_index = (new_index - rnum + n) % n;
    vector<Int> ans(n);
    for (Int i = 0; i < n; i++) {
        ans[(index + i) % n] = res[(new_index + i) % n];
    }
    for (Int i = 0; i < n; i++) {
        dump(ans[i]);
    }
    return 0;
}
