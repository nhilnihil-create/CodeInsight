#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    int mn = 1, mnv = 1e9 + 10;
    rep(i, 0, N) {
        int a, b;
        cin >> a >> b;
        if(mnv > b) {
            mnv = b;
            mn = a;
        }
    }
    cout << mn + mnv << endl;
    return 0;
}
