#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll a, b, h[100005] = {};
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) cin >> h[i];
    ll l = 0, r = mod;
    while (l + 1 < r) {
        ll m = (l + r) >> 1, c = 0;
        for (int i = 0; i < n; i++) if (h[i] > m * b) {
            c += (h[i] - m * b - 1) / (a - b) + 1;
        }
        if (c <= m) r = m;
        else l = m;
    }
    cout << r;
}
