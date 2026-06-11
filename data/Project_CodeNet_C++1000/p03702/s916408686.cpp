#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 5;
int mon[maxn];
LL n, a, b;

bool check(LL m)
{
    LL cnt1 = m * b, cnt2 = a - b;
    vector<LL> q;
    for(int i = 0; i < n; i++)
        if(mon[i] > cnt1)
            q.push_back(mon[i] - cnt1);

    LL cnt = 0;
    for(int i = 0; i < q.size(); i++)
    {
        if(q[i] % cnt2 != 0)
            cnt += q[i] / cnt2 + 1;
        else if(q[i] % cnt2 == 0)
            cnt += q[i] / cnt2;
    }
    if(cnt <= m)
        return true;
    return false;
}

int main()
{
    while(~scanf("%lld%lld%lld", &n, &a, &b))
    {
        for(LL i = 0; i < n; i++)
            scanf("%lld", &mon[i]);

        LL r = 1000000000 + 5, l = 1;

        while(l < r)
        {
            LL mid = l + (r - l) / 2;
            if(check(mid))
                r = mid;
            else
                l = mid + 1;
        }

        printf("%lld\n", l);
    }
    return 0;
}
