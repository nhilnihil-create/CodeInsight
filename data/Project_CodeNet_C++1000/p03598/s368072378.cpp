#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N, K;
        cin >> N >> K;
        vector<ll> X(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> X[i];
        }
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
                ans += min(X[i] * 2, (K-X[i]) * 2);
        }
        cout << ans << endl;
}
