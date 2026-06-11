#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=200005;
const ll INF=0x3f3f3f3f;
const ll MOD=1000000007;
ll n,m,a[MAX],d[MAX],tilt=0,now=0,u[MAX],ans=INF;
vector<pll> slope;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=0;i<n;i++) scanf("%lld",&a[i]),a[i]--;
    for(ll i=0;i<n-1;i++){
        d[i]=(a[i+1]-a[i]+m)%m-1;
        if(a[i+1]-d[i]<0) tilt--;
        u[a[i+1]]+=d[i];

        slope.push_back(make_pair(a[i+1],1));
        slope.push_back(make_pair((a[i+1]-d[i]+m)%m,-1));
        now+=min(d[i],a[i+1])+1;
    }
    ll idx=0;
    sort(slope.begin(),slope.end());
    ans=now;
    for(ll i=1;i<m;i++){
        for(;idx<slope.size();idx++) {
            if(slope[idx].first>=i) break;
            tilt+=slope[idx].second;
        }
        //printf("%lld %lld\n",now,tilt);
        now+=tilt+u[i-1];
        ans=min(now,ans);
    }
    printf("%lld\n",ans);
}
