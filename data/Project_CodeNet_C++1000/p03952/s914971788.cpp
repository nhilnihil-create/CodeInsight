#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N, x;
    cin >> N >> x;
    if(x == 1 || x == 2 * N - 1) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int a = x - N + 1;
        if(a <= 0) a += (2 * N - 1);
        rep(i, 0, 2 * N - 1) {
            if(a == 2 * N) a = 1;
            cout << a++ << '\n';
        }
    }
    return 0;
}
