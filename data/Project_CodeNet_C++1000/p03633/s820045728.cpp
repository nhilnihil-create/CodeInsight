#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b) * b);
}

int main(void)
{
    int N;
    cin >> N;

    vector<ll> T(N);
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }

    ll ans = T[0];
    for (int i = 1; i < N; i++)
    {
        ans = lcm(ans, T[i]);
    }
    cout << ans << endl;
    return (0);
}