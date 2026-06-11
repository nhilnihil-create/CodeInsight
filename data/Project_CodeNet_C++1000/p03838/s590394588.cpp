#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    {
        int ans = ~1U >> 1;
        if ( x <=  y) ans = min(ans,  y - x + 0);
        if (-x <=  y) ans = min(ans,  y + x + 1);
        if ( x <= -y) ans = min(ans, -y - x + 1);
        if (-x <= -y) ans = min(ans, -y + x + 2);
        cout << ans << endl;
    }
    return 0;
}
