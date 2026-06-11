#include <iostream>
using namespace std;
int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    const int dx = tx - sx, dy = ty - sy;
    string ans="";
    // Path 1
    ans += string(dx, 'R') + string(dy, 'U');
    // Path 2
    ans += string(dx, 'L') + string(dy, 'D');
    // Path 3
    ans += 'D' + string(dx+1, 'R') + string(dy+1, 'U') + 'L';
    // Path 4
    ans += 'U' + string(dx+1, 'L') + string(dy+1, 'D') + 'R';
    cout << ans << endl;
}