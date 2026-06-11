#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repi(i,x,n) for(ll i=x;i<(ll)(n);i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
//cin.tie(0);ios::sync_with_stdio(false);



signed main(){
    ll w,h,ans=0;cin>>w>>h;
    vector<ll> x(w),y(h),ysum(h+1,0);

    rep(i,w){
        cin>>x[i];
        ans+=x[i];
    }

    rep(i,h){
        cin>>y[i];
        ans+=y[i];
    }

    sort(all(x));
    sort(all(y));

    rep(i,h)ysum[i+1]=ysum[i]+y[i];

    rep(i,w){
        ll itr=ub(all(y),x[i])-y.begin();
        ans+=(h-1-itr+1)*x[i];
        ans+=ysum.at(itr);
    }

    cout<<ans<<endl;
}