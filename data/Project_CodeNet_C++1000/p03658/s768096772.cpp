#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        ll N, K;
        cin >> N >> K;
        vector<ll> L(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> L[i];
        }
        sort(L.begin(), L.end(), greater<ll>());
        ll ans = 0;
        for (int i = 0; i < K; ++i) {
                ans += L[i];
        }
        cout << ans << endl;


}
