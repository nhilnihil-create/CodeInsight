#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL ans;

void get(LL p,LL q)
{
    if(p % q == 0)
    {
        ans += p * 2 - q;
        return;
    }
    else
    {
        ans += (p - p % q) * 2;
        get(q,p%q);
    }
}

int main()
{
    LL n,m,a,b;
    cin >> n >> m;
    ans = n;
    n -= m;
    a = max(n,m),b = min(n,m);
    get(a,b);
    cout << ans << endl;
    return 0;
}