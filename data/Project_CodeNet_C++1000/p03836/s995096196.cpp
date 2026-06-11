#include <iostream>
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string x1, x2, y1, y2;
    x1 = 'R';
    x2 = 'L';
    y1 = 'U';
    y2 = 'D';
    string ans;
    ans = "";
    int dx, dy;
    dx = tx - sx;
    dy = ty - sy;
    for (int i=0; i<dx; i++) ans += x1;
    for (int i=0; i<dy; i++) ans += y1;
    for (int i=0; i<dx; i++) ans += x2;
    for (int i=0; i<dy; i++) ans += y2;
    // 2週目
    ans += y2;
    for (int i=0; i<dx; i++) ans += x1;
    ans += x1;
    for (int i=0; i<dy; i++) ans += y1;
    ans += y1;
    ans += x2;
    ans += y1;
    for (int i=0; i<dx; i++) ans += x2;
    ans += x2;
    for (int i=0; i<dy; i++) ans += y2;
    ans += y2;
    ans += x1;
    cout << ans << endl;
}