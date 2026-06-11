#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);
    sort(s.begin(), s.end());
    for (auto line : s) cout << line;
    cout << endl;
}
