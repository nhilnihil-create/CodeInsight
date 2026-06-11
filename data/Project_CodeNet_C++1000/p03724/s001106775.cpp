#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m;
ll a[100005];
ll cnt = 0;

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < m * 2; i++)
    {
        ll t;
        scanf("%lld", &t);
        a[t] ^= 1;
        cnt += a[t] * 2 - 1;
    }
    if(cnt) printf("NO\n");
    else printf("YES");
    return 0;
}
