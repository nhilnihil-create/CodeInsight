#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define INF ((ll)1e18)

int n;
const int sz=1e6;
ll a[sz],lmax[sz],rmin[sz];
void solve()
{
    priority_queue<ll,vector<ll>,greater<ll> >que;
    lmax[0]=0;
    for(int i=0;i<n;i++)
    {
        lmax[0]+=a[i];
        que.push(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        que.push(a[n+i-1]);
        lmax[i]=lmax[i-1]-que.top()+a[n+i-1];
        que.pop();
    }
    for(int i=0;i<=n;i++)cerr<<i<<": "<<lmax[i]<<endl;

    priority_queue<ll> que2;
    rmin[0]=0;
    for(int i=0;i<n;i++)
    {
        rmin[0]+=a[3*n-1-i];
        que2.push(a[3*n-1-i]);
    }
    for(int i=1;i<=n;i++)
    {
        que2.push(a[2*n-i]);
        rmin[i]=rmin[i-1]-que2.top()+a[2*n-i];
        que2.pop();
    }
    for(int i=0;i<=n;i++)cerr<<i<<": "<<rmin[i]<<endl;

    ll res=-INF;
    for(int i=0;i<=n;i++)
    {
        ll ch;
        ch=lmax[i]-rmin[n-i];
        if(ch>res)res=ch;

    }
    cout<<res<<endl;
    return;
}
main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    for(int i=0;i<3*n;i++)scanf("%lld",a+i);
    solve();
    return 0;
}