#include<bits/stdc++.h>
#define ll long long
const int maxn = int(1e5) + 7;
using namespace std;
ll inf=1e9+7;
ll a[900009];
ll sum[20];
int main()
{
    ll h,w,n;
    scanf("%lld%lld%lld",&h,&w,&n);
    ll x,y;
    int k=0;
    ll zo=(h-2)*(w-2);
    for(ll i=1;i<=n;i++)
    {
        //cin>>x>>y;
        scanf("%lld%lld",&x,&y);
        for(ll i=0;i<=2;i++)
        for(ll j=0;j<=2;j++)
        {
            if(x-i>=1&&x-i<=h-2&&y-j>=1&&y-j<=w-2)
            {

                a[k++]=inf*(x-i)+(y-j);
            }
        }
    }
    sort(a,a+k);
    ll t=1;
    for(int i=0;i<k;i++)
    {
        if(a[i]==a[i+1])t++;
        else
        {
            sum[t]++;t=1;zo--;
        }
    }
    cout<<zo<<endl;
    for(int i=1;i<=9;i++)
    {
        cout<<sum[i]<<endl;
    }
}
