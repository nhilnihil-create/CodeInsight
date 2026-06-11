
#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    ll S, C;
    cin >> S >> C;

    ll ans = 0;
    if (C > S * 2)
    {
        ans += S;
        C -= S * 2;
        ans += C / 4;
    }
    else
    {
        ans = C / 2;
    }
    // printf("%lld %lld\n", S, C);
    cout << ans << endl;
    return (0);
}