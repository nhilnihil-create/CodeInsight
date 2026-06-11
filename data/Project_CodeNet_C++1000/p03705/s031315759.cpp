#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int n, a, b; cin >> n >> a >> b;
    if (a > b) {
        cout << 0;
        return 0;
    }
    if (n == 1 && a != b) {
        cout << 0;
        return 0;
    }
    cout << (b-a) * (n - 2) + 1 << endl;
}