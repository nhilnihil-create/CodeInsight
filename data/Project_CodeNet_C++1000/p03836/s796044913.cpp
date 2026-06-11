#include <bits/stdc++.h>
using namespace std;

int main() {
    int sx, sy, gx, gy;  cin >> sx >> sy >> gx >> gy;
    string ans = string();
    ans += string(gy - sy, 'U') + string(gx - sx, 'R');
    ans += string(gy - sy, 'D') + string(gx - sx, 'L');
    ans += 'L' + string(gy - sy + 1, 'U') + string(gx - sx + 1, 'R') + 'D';
    ans += 'R' + string(gy - sy + 1, 'D') + string(gx - sx + 1, 'L') + 'U';
    cout << ans << endl;
}
