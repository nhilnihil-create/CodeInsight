#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll f(ll a, ll b) {
    if (a > b) swap(a, b);
    if (b % a == 0) {
        // cout << "(" << a << "," << b << "): " << (2 * (b / a) - 1) * a << endl;
        return (2 * (b / a) - 1) * a;
    }
    // cout << "(" << a << "," << b << "): " << 2 * (b / a) * a << " + f(" << b % a << "," << a << ")" << endl;
    return 2 * (b / a) * a + f(b % a, a);
}

int main() {
    ll N, X; cin >> N >> X;
    cout << N + f(X, N - X) << endl;
    return 0;
}