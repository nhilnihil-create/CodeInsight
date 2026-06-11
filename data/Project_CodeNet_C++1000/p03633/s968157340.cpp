#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n;
ll p, t;

int main() {
    cin >> n;
    p = 1;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        ll g = __gcd(p, t);
        p = p / g * t;
    }
    cout << p << endl;
    return 0;
}
