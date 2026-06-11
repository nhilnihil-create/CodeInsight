#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool judge(ll x)
{
    printf("? %lld\n",x);
    fflush(stdout);
    char C;
    scanf(" %c",&C);
    return C == 'Y';
}

int main()
{
    ll ans = 1000000000;
    if(judge(ans))
    {
        ans = 10;
        while(!judge(ans - 1))ans *= 10;
        printf("! %lld\n",ans / 10);
        fflush(stdout);
        return 0;
    }
    else
    {
        while(!judge(ans /= 10));
        ll l = ans,r = ans * 10;
        while(r - l > 1)
        {
            ll mid = (l + r) / 2;
            if(judge(mid * 10))r = mid;
            else l = mid;
        }
        printf("! %lld\n",r);
        fflush(stdout);
        return 0;
    }
}
