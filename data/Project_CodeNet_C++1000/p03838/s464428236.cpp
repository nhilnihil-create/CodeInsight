#include <iostream>
using namespace std;

int main() {
    long long x, y; cin >> x >> y;
    long long ans = 1LL<<60;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long res = i + j;
            long long xx = x * (i ? -1 : 1);
            long long yy = y * (j ? -1 : 1);
            if (xx <= yy) ans = min(ans, res + yy - xx);
        }
    }
    cout << ans << endl;
}