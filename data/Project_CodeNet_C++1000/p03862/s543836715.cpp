#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    if (a[1] + a[0] > x) {
        ans += a[1] + a[0] - x;
        if (a[1] + a[0] - x <= a[1]) {
            a[1] -= a[1] + a[0] - x;
        } else {
            a[1] = 0;
            a[0] = x;
        }
    }
    for (int i = 1; i < N; i++) {
        if (a[i] + a[i - 1] > x) {
            ans += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    cout << ans << endl;
}
