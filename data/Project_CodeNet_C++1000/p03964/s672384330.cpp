#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;

void solve() {
    cin >> N;
    ll T = 1;
    ll A = 1;
    for (int i = 0; i < N; ++i) {
        ll t, a;
        cin >> t >> a;
        ll n = max((T - 1) / t + 1, (A - 1) / a + 1);
        T = n * t;
        A = n * a;
    }
    cout << A + T << endl;
}

int main() {
    solve();
    return 0;
}
