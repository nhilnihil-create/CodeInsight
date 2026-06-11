#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;


int main() {
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n, 0LL);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (2 * sum % (n * (n + 1)) != 0) {
        cout << "NO" << endl;
        return 0;
    }

    ll k = 2 * sum / (n * (n + 1));

    vector<ll> d(n, 0LL), t(n, 0LL);
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) d[i] = a[0] - a[n - 1];
        else d[i] = a[i] - a[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        if (k - d[i] < 0 || (k - d[i]) % n != 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (i == 0) {
            t[n - 1] = (k - d[i]) / n;
            cnt += t[n - 1];
        } else {
            t[i - 1] = (k - d[i]) / n;
            cnt += t[i - 1];
        }
    }

    if (cnt != k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
