#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    vector<int> n(3);
    rep(i, 3) cin >> n.at(i);
    sort(n.begin(), n.end());
    if (n.at(0) == 5 && n.at(1) == 5 && n.at(2) == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

