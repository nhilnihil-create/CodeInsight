#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    ll ret = 0;
    for (int i = 0; i <= 30; i++) {
        ll now = 0;
        for (auto x:v) {
            if ((k | x[0]) == k)now += x[1];
        }
        ret = max(ret, now);

        if (k & (1 << i)) {
            k ^= 1 << i;
            for (int j = i - 1; j >= 0; j--)k |= 1 << j;
        }
    }

    cout << ret << endl;
    return 0;
}