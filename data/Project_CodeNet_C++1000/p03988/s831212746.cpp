
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 1e2;
int n, a[nsz + 5], cnt[nsz + 5];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    cont (i, n) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a + 1, a + n + 1);
    int mn = a[1], mx = a[n];
    if (cnt[mn] == 1) {
        if (mx != 2 * mn) {
            cout << "Impossible" << ln;
            return 0;
        }
        circ (d, mn + 1, mx) {
            if (cnt[d] < 2) {
                cout << "Impossible" << ln;
                return 0;
            }
        }
    } else if (cnt[mn] == 2) {
        if (mx != 2 * mn - 1) {
            cout << "Impossible" << ln;
            return 0;
        }
        circ (d, mn + 1, mx) {
            if (cnt[d] < 2) {
                cout << "Impossible" << ln;
                return 0;
            }
        }
    } else {
        cout << "Impossible" << ln;
        return 0;
    }
    cout << "Possible" << ln;
}