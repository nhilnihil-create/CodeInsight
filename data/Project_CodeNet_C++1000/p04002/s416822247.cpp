#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int h, w, n, a[100005] = {}, b[100005] = {};
    set<pii> s, z[10] = {};
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i], s.insert({a[i], b[i]});
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (a[i] + j - 1 > 0 && a[i] + j + 1 <= h && b[i] + k - 1 > 0 && b[i] + k + 1 <= w) {
                    int c = 0;
                    for (int l = -1; l <= 1; l++) {
                        for (int m = -1; m <= 1; m++) {
                            if (s.find({a[i] + j + l, b[i] + k + m}) != s.end()) c++;
                        }
                    }
                    z[c].insert({a[i] + j, b[i] + k});
                }
            }
        }
    }
    ll y = (ll)(h - 2) * (w - 2);
    for (int i = 1; i <= 9; i++) y -= z[i].size();
    cout << y << '\n';
    for (int i = 1; i <= 9; i++) cout << z[i].size() << '\n';
}
