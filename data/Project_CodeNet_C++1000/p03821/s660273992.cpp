#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];

    ll acc = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) continue;

        a[i] += acc;
        if (a[i] < b[i])
            acc += b[i] - a[i];
        else {
            if (a[i] % b[i] != 0) acc += b[i] - a[i] % b[i];
        }
    }

    cout << acc << endl;
    return 0;
}
