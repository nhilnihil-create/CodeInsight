#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int n, ans = 0, cnt = 0;
    int a[7] = {1, 2, 4, 8, 16, 32, 64};

    cin >> n;
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    rep(i, 7) {
        if (a[i] > n) {
            cout << a[i - 1] << endl;
            return 0;
        } else if (a[i] == n) {
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << a[6] << endl;
    return 0;
}