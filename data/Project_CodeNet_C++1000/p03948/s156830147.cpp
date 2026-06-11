#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //Let's Concentrate on learning
    //Rating ka kya hai aaj niche to kl upar...
    ll t=1;
    // cin>>t;
    while(t--)
    {
        int n,t;
        cin>>n>>t;
        vector<int> a(n),ma(n,0),co(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ma[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ma[i]=max(a[i],ma[i+1]);
        }
        int maxi=0,count=0;
        for(int i=0;i<n-1;i++)
        {
            co[i]=max(0,ma[i+1]-a[i]);
            maxi=max(maxi,co[i]);
        }
        for(int i=0;i<n-1;i++)
        if(co[i]==maxi)
        {
            count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}