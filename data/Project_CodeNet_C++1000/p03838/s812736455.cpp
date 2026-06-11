#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;


int main() {
    int x, y;
    cin >> x >> y;

    int ans = abs(abs(x) - abs(y));
    if (x > y && y > 0) ans += 2;
    else if (x < 0 && 0 < y) ans++;
    else if (y <= 0 && 0 <= x) ans++;
    else if (y < x && x < 0) ans += 2;

    cout << ans << endl;

    return 0;
}