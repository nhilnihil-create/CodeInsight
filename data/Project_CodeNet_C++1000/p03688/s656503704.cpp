#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n;
ll a[100005];
ll x, y;

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    if(a[n - 1] - a[0] > 1)
    {
        printf("No\n");
        return 0;
    }
    if(a[n - 1] == a[0])
    {
        if(a[0] == n - 1) printf("Yes\n");
        else if(a[0] <= n / 2) printf("Yes\n");
        else printf("No\n");
        return 0;
    }
    x = upper_bound(a, a + n, a[0]) - lower_bound(a, a + n, a[0]);
    y = n - x;
    if(x + y / 2 < a[n - 1]) printf("No\n");
    else if(a[n - 1] >= n) printf("No\n");
    else if(a[n - 1] <= x) printf("No\n");
    else if(y <= 1) printf("No\n");
    else printf("Yes\n");
    return 0;
}
