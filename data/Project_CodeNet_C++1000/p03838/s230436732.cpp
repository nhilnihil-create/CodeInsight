#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

 

int main() {
    int x, y;
    cin >> x >> y;
    int ans =INFINITY;
    if (y - x > 0) ans = min(ans, y - x);
    if (y - (-x) >= 0) ans = min(ans, y - (-x) + 1);
    if (-y - x >= 0) ans = min(ans, -y - x + 1);
    if (-y - (-x) >= 0) ans = min(ans, -y - (-x) + 2);
    cout << ans << endl;
}
