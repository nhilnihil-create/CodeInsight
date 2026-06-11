#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x;
    cin >> x;
    ll t = 0;
    for (int i = 1;; ++i) {
        t += i;
        if (t >= x) {
            cout << i;
            return 0;
        }
    }
    return 0;
}