#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t=1;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+5];
        map<ll,ll>cnt;
        for(ll i=1; i<=n; i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }

        ll ans=0;
        vector<ll>v;
        sort(a+1,a+n+1);

        for(ll i=n; i>=1; i--)
        {


            if(cnt[a[i]]>=4)
            {
                ans=max(ans,(a[i]*a[i]));

            }
            if(v.size()>=2) {
                ans=max(ans,v[0]*v[1]);
            }
            if(cnt[a[i]]>=2&&v.size()<2) v.push_back(a[i]);
            cnt[a[i]]=0;
        }
        cout<<ans<<endl;
        v.clear();
        cnt.clear();
    }
}
