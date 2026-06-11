#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int inf = 2000000000;

int main() {
    int x, y;
    cin >> x >> y;

    int ans = inf;
    if (y >= x) ans = min(ans, y - x);
    if (y >= -x) ans = min(ans, y + x + 1);
    if (-y >= x) ans = min(ans, -y - x + 1);
    if (-y >= -x) ans = min(ans, -y + x + 2);

    cout << ans << endl;
    return 0;
}