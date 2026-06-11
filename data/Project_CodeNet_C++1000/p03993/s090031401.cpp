//median time 23

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i, n, init) for (ll i = init; i < (n); i++)
#define repd(i, n, init) for (ll i = (n); i >= init; i--)
#define repm(i, m) for (auto i = m.begin(); i != m.end(); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    repi(i, N, 0)
    {
        cin >> A[i];
    }
    ll cnt = 0;
    for (ll i = 0; i < N; i++)
    {
        if (A.at(A.at(i) - 1) == i + 1)
        {
            cnt++;
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}