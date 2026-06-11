#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int a, b, c; cin >> a >> b >> c;

    int ans = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        if (a == b && b == c) {
            cout << -1 << endl;
            return 0;
        }
        
        int na = b / 2 + c / 2;
        int nb = a / 2 + c / 2;
        int nc = a / 2 + b / 2;
        a = na;
        b = nb;
        c = nc;

        ans++;

    }

    cout << ans << endl;
}