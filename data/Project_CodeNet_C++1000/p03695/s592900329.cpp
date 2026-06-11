#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int Cnt, n, t, add, cnt[10];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t >= 3200) {
            ++add;
            continue;
        }
        int o;
        if (t < 400) {
            o = 0;
        } else if (t < 800) {
            o = 1;
        } else if (t < 1200) {
            o = 2;
        } else if (t < 1600) {
            o = 3;
        } else if (t < 2000) {
            o = 4;
        } else if (t < 2400) {
            o = 5;
        } else if (t < 2800) {
            o = 6;
        } else if (t < 3200) {
            o = 7;
        }
        if (cnt[o]++ == 0) {
            ++Cnt;
        }
    }
    cout << max(1, Cnt) << ' ' << Cnt + add  << endl;
    return 0;
}
