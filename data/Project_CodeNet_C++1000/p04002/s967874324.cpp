#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+10;
ll inf=1e9+7;
ll a[900009];
ll ans[20];
int main()
{
    ll h,w,n;
    scanf("%lld%lld%lld",&h,&w,&n);
    memset(ans,0,sizeof(ans));
    int cnt=0;
    ll sum=(h-2)*(w-2);
    for(ll k=1; k<=n; k++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        for(ll i=0; i<=2; i++)
            for(ll j=0; j<=2; j++)
            {
                if(x-i>=1&&x-i<=h-2&&y-j>=1&&y-j<=w-2)
                {
                    a[cnt++]=inf*(x-i)+(y-j);
                }
            }
    }
    sort(a,a+cnt);
    ll t=1;
    for(int i=0; i<cnt; i++)
    {
        if(a[i]==a[i+1])
            t++;
        else
        {
            ans[t]++;
            t=1;
            sum--;
        }
    }
    printf("%lld\n",sum);
    for(int i=1; i<=9; i++)
        printf("%lld\n",ans[i]);
}
