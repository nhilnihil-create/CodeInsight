#include <bits/stdc++.h>
using namespace std;

#define rep(i, j) for (int i = 0; i < j; i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vi p(n), a(n), b(n);
    rep(i, n) cin >> p[i];

    vpii pp(n);
    rep(i, n) {
        pp[i].first = p[i];
        pp[i].second = i + 1;
    }
    sort(all(pp));
    rep(i, n) {
        p[i] = n - pp[i].second;
        // cout << p[i] << " ";
    }
    // cout << endl;

    a[0] = 1e9;
    b[0] = 1;

    int base = a[0] + b[0];

    for (int i = 1; i < n; i++) {
        a[i] = a[i - 1] - 1;
        b[i] = b[i - 1] + 1;
        int x = (base + p[0]) - (a[i] + b[i] + p[i]);
        // int x = a[i] + b[i] + (n - p[i]);
        // x -= base;
        // cout << i << " " << x << endl;
        if (x > 0) {
            b[i] += x;
        } else {
            a[i] += x;
        }
    }

    rep(i, n) {
        cout << b[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    rep(i, n) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
