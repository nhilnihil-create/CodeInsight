#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    int ans;
    if (x <= y && (0 <= x || y <= 0)) ans = y - x;
    else if (y < x && (0 < y || x < 0)) ans = x - y + 2;
    else ans = abs(abs(x) - abs(y)) + 1;
    cout << ans << endl;
    return 0;
}
