#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

int main() {
    int n;
    ll time = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        time = (time / gcd<ll>(t, time)) * t;
    }
    cout << time << endl;
    return 0;
}