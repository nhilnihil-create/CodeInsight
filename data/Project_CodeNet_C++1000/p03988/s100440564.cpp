#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    int uk = 0;
    while (uk < n && a[uk] == a[0]) {
        ++cnt;
        ++uk;
    }
    if (cnt > 2) {
        cout << "Impossible\n";
        return 0;
    }
    if (cnt == 1) {
        if (a.back() > 2 * a[0]) {
            cout << "Impossible\n";
            return 0;
        }
    } else {
        if (a.back() >= 2 * a[0]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 1) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
}