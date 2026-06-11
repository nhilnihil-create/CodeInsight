#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            if (a[i] != (i / 2) * 2 + 1) {
                cout << 0 << endl;
                return 0;
            }
        }

    } else {
        if (a[0] != 0) {
            cout << 0 << endl;
            return 0;
        }
        for (int i = 1; i < n; i++) {
            if (a[i] != ((i + 1) / 2) * 2) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    long long int sum = 1;
    for (int i = 0; i < a.size() / 2; i++) {
        sum *= 2;
        sum %= 1000000007;
    }

    cout << sum << endl;
}