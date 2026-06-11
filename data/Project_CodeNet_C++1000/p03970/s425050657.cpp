#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string src = "CODEFESTIVAL2016";
    string s;
    cin >> s;
    int cnt = 0;
    rep(i, 16) if (src.at(i) != s.at(i)) cnt++;
    cout << cnt << endl;
}
