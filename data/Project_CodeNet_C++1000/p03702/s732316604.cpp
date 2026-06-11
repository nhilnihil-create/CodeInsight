#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll A,B;
ll D;
int N;
ll h[100005];
int solve(ll n)
{
    ll sum=B*n;
    for(int i=0;i<N;i++)
    {
        if(h[i]>sum)
        {
            n-=(h[i]-sum)/D;
            if((h[i]-sum)%D)
                n--;
        }
    }
    if(n<0)
        return 0;
    else
        return 1;
}
int main()
{

    scanf("%d",&N);
    scanf("%lld%lld",&A,&B);
    D=A-B;
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&h[i]);

    }
    ll l=1;
    ll r=1e9;
    ll mid=(l+r)/2;
    while(l<r)
    {
        int flag=solve(mid);
        if(flag)
            r=mid;
        else
            l=mid+1;
        mid=(l+r)/2;
    }

    printf("%lld",l);
}
