#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,ans=-INF; cin>>n>>k;
    vector<ll> a(n,0),sum(n+1,0),psum(n+1,0);
    rep(i,n) cin>>a[i];
    rep(i,n){
        sum[i+1]=sum[i]+a[i];
        psum[i+1]=psum[i];
        if(a[i]>0) psum[i+1]+=a[i];
    }
    for(int i=0;i<n-k+1;i++){
        ll d=sum[i+k]-sum[i],cnt;
        cnt=psum[i]+psum[n]-psum[i+k];
        ans=max(ans,max(cnt,cnt+d));
    }
    cout<<ans<<endl;

}
