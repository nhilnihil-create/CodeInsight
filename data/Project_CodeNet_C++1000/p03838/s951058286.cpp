#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    {
        int ans, ax = abs(x), ay = abs(y);
        if (ax == ay) ans = x != y;
        if (ax < ay) ans = ay - ax + (x < 0) + (y < 0);
        if (ax > ay) ans = ax - ay + (x > 0) + (y > 0);
        cout << ans << endl;
    }
    return 0;
}
