#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

int main() {
    ll N, x;
    cin >> N >> x;
    ll M = 2 * N - 1;

    if (x == 1 || x == M) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    ll a = 2;
    for (ll i = 1; i < N - 1; i++) {
        if (a == x)
            a++;
        cout << a << endl;
        a++;
    }
    cout << 1 << endl;
    cout << x << endl;
    cout << M << endl;
    for (ll i = 1; i < N - 1; i++) {
        if (a == x)
            a++;
        cout << a << endl;
        a++;
    }
}
