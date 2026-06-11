#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    ll w = -1, h = -1;

    for (int i = 0; i < n - 1; i++) {
        if (w < 0) {
            if (a[i] == a[i + 1]) {
                w = a[i];
                i++;
            }

        } else {
            if (a[i] == a[i + 1]) {
                h = a[i];
                break;
            }
        }
    }

    if (h > 0 && w > 0) {
        cout << w * h << endl;
    } else {
        cout << 0 << endl;
    }
}