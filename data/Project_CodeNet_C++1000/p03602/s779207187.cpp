#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
using namespace std;

main(){
    int n;
    cin>>n;
    ll a[400][400];
    rep(i,n)rep(j,n)cin>>a[i][j];
    ll ans=0;
    rep(i,n){
        rep2(j,i+1,n-1){
            ll temp=a[i][j];
            ll m=INF;
            rep(k,n){
                if(k==i||k==j)continue;
                m=min(m,a[i][k]+a[k][j]);
            }
            if(m<temp){ 
                ans=-1;break;
            }
            else if(m>temp)ans+=temp;
        }
        if(ans==-1)break;
    }
    printf("%lld",ans);
}