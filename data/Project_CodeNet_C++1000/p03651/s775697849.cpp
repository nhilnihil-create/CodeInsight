#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    bool ok = false;
    rep(i,n) {
        cin >> a.at(i);
    }

    sort(a.rbegin(), a.rend());
    int g = 1e9 + 5;
    if (k <= a.at(0)) {
        rep(i,n) {
            if (k == a.at(i)) ok = true;
            if (0 < i) g = min(g, gcd(a.at(i), a.at(i-1)));
        }
    }

    if (k % g == 0) ok = true;

    if (ok) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}