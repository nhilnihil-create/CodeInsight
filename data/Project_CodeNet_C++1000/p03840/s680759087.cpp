#include <iostream>
using namespace std;
int main() {
    long long i, o, t, j, l, s, z; cin >> i >> o >> t >> j >> l >> s >> z;
    long long ans = 0;
    ans += o;
    ans += 2 * (i/2 + j/2 + l/2);
    switch (i %2 + j % 2 + l % 2) {
    case 0:
    case 1: break;
    case 2: if (i > 0 && j > 0 && l > 0) ans += 1; break;
    case 3: ans += 3; break;
    }
    cout << ans << endl;
}
