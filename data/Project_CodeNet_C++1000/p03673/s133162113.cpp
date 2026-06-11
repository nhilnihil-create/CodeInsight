#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a;

    rep(i, n) {
        ll x;
        cin >> x;
        if (i % 2 == 0)
            a.push_back(x);
        else
            a.insert(a.begin(), x);
    }
    if (n % 2 == 1) reverse(a.begin(), a.end());

    rep(i, n) {
        cout << a[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << ' ';
    }
    return 0;
}
