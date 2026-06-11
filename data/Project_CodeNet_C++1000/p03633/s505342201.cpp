#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int N;
    cin >> N;
    v<ll> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }
    ll ans = T[0];

    for (int i = 0; i < N; i++)
    {
        ans = lcm(ans, T[i]);
    }

    cout << ans << endl;
    return 0;
}