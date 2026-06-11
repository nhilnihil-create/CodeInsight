#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, ans;
ll a, b;
ll h[100005];

bool f(ll p)
{
    ll cnt = 0;
    for(ll i = 0; i < n; i++)
    {
        ll t = h[i];
        t -= b * p;
        if(t <= 0) continue;
        cnt += (t + a - 1) / a;
    }
    if(cnt <= p) return true;
    else return false;
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    a -= b;
    for(ll i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
    }
    ll lt = 0, rt = 1e9, mid;
    while(lt < rt)
    {
        mid = (lt + rt) / 2;
        if(f(mid)) rt = mid, ans = mid;
        else lt = mid + 1;
    }
    printf("%d", ans);
    return 0;
}
