#include <bits/stdc++.h>
using namespace std;

#define INF 1e18

using ll = long long;

int a[20];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];     

    ll ans=INF;

    int sz=1<<n;
    for(int p=0;p<sz;p++)
    {
        int m=0;
        int cnt=0;
        ll cost=0;
        for(int i=0;i<n;i++)
        {
            if(cnt>=k)continue;
            if(m<a[i])
            {
                m=a[i];
                cnt++;
                continue;
            }
            if(p&(1<<i))
            {
                m=m+1;
                cost+=m-a[i];
                cnt++;
            }
        }

        if(cnt>=k)ans=min(ans,cost);
    }

    cout<<ans<<"\n";

    return 0;
}
