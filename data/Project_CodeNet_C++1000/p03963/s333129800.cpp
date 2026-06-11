#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    llint n, k;
    cin >> n >> k;

    llint total = k;
    rep(i, n - 1) total *= (k - 1);
    cout << total << endl;
}
