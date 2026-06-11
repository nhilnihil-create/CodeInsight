#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    bool ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (x & 1) ans = ans ^ 1;
    }
    if (!ans) cout << "YES";
    else cout << "NO";
    return 0;
}