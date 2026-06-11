
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b)
{
        if (b == 0) return a;
        return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
        return a / gcd(a, b) * b;
}

int main()
{
        ll N;
        cin >> N;
        vector<ll> T(N, 0);
        for (int i = 0; i < N; ++i) {
                cin >> T[i];
        }

        ll ans = 1;
        for (int i = 0; i < N; ++i) {
                ans = lcm(ans, T[i]);
        }
        cout << ans << endl;

}
