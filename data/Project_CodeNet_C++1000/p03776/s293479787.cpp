#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
ll a, b;
ll c[55];
ll d[55][55];
ll ans, ans2;
ll cnt, cnt2;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld%lld%lld", &n, &a, &b);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &c[i]);
    }
    sort(c, c + n, greater<ll>());
    d[0][0] = 1;
    for(ll i = 1; i <= 50; i++)
    {
        d[i][0] = 1;
        for(ll j = 1; j <= i; j++) d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
    }
    for(ll i = 0; i < a; i++)
    {
        ans += c[i];
    }
    printf("%.9f\n", (double)ans / a);
    for(ll i = a - 1; i >= 0; i--)
    {
        if(c[i] == c[a - 1]) cnt++;
    }
    cnt2 = cnt;
    for(ll i = a; i < n; i++)
    {
        if(c[i] == c[a - 1]) cnt2++;
    }
    if(c[0] != c[a - 1])
    {
        printf("%lld", d[cnt2][cnt]);
    }
    else
    {
        for(ll i = a; i <= b; i++) ans2 += d[cnt2][i];
        printf("%lld", ans2);
    }
    return 0;
}
