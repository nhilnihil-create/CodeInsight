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

    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }

    vll b, c;
 

    rep(i, n) {
        if (i % 2)
            b.emplace_back(a[i]);
        else
            c.emplace_back(a[i]);
    }

    if (n % 2) {
        reverse(c.begin(), c.end());
        for (int i = 0; i < c.size(); i++) {
            cout << c[i] << " ";
        }
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }

        cout << endl;
    } else {
        reverse(b.begin(), b.end());

        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        for (int i = 0; i < c.size(); i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }
}