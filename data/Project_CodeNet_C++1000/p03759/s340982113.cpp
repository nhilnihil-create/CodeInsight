#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // string ans = (b - a == c - b) ? "YES" : "NO";
    // cout << ans << endl;

    cout << (b - a == c - b ? "YES" : "NO") << endl;

    return 0;
}