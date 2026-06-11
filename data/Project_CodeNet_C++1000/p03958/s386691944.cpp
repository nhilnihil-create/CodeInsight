#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, T;
    cin >> K >> T;

    int mx = 0;
    for (int i = 0; i < T; ++i) {
        int a;
        cin >> a;
        mx = max(mx, a);
    }
    cout << max(2 * mx - K - 1, 0) << endl;
    return 0;
}
