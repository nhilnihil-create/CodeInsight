#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll N, time;
    cin >> N >> time;

    vector<ll> t(N);
    for (int i = 0; i < N; i++)
    {
        cin >> t[i];
    }

    reverse(t.begin(), t.end());
    vector<ll> ruiseki(N + 1, 0);
    ll diff;
    ruiseki[0] = time;
    for (int i = 0; i < N; ++i)
    {
        diff = t[i] - t[i + 1];
        ruiseki[i + 1] = ruiseki[i] + min(diff, time);
    }

    // debug
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%lld ", ruiseki[i]);
    // }
    ll ans = ruiseki[N - 1];
    cout << ans << endl;
}