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

    vector<ll> d(n, 0LL);
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) d[i] = a[0] - a[n - 1] - k;
        else d[i] = a[i] - a[i - 1] - k;

        if (d[i] > 0 || d[i] % n) {
            cout << "NO" << endl;
            return 0;
        }
        cnt -= d[i] / n;
    }

    cout << (cnt == k ? "YES" : "NO") << endl;

}