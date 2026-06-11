#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n, tmp = 0, cnt = 1;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i < n-1; i++) {
        if (a[i] < a[i + 1]) {
            if (tmp == -1) {
                cnt++;
                tmp = 0;
            } else {
                tmp = 1;
            }
        }

        if (a[i] > a[i + 1]) {
            if (tmp == 1) {
                cnt++;
                tmp = 0;
            } else {
                tmp = -1;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}