#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll a[100005];
ll sum;
ll x;
ll cnt;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if(sum % (n * (n + 1) / 2) > 0)
    {
        printf("NO");
        return 0;
    }
    x = sum / (n * (n + 1) / 2);
    for(ll i = 0; i < n; i++)
    {
        ll t1 = a[i];
        ll t2 = a[(i + 1) % n];
        ll t3 = (t2 - t1);
        ll t4 = x - t3;
        if(t4 < 0)
        {
            printf("NO");
            return 0;
        }
        if(t4 % n > 0)
        {
            printf("NO");
            return 0;
        }
        cnt += t4 / n;
    }
    if(cnt == x)
    {
        printf("YES");
    }
    else printf("NO");
    return 0;
}
