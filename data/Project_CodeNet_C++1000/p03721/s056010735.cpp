#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    map<ll, ll> a;
    for (int i = 0; i < N; i++) {
        ll tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        a[tmp_a] += tmp_b;
    }

    for (auto num : a) {
        K -= num.second;
        if (K <= 0) {
            cout << num.first << endl;
            return 0;
        }
    }

    return 0;
}
