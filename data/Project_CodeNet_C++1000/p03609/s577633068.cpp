#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {
    int X, t;

    cin >> X >> t;

    int ans = X - t;

    if (ans > 0) {
        cout << ans << endl;
    } else if ((ans == 0) || (ans < 0)) {
        cout << 0 << endl;
    }

    return 0;
}