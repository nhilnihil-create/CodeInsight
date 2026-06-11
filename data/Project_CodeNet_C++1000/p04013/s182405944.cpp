#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main(){
    ll N,A;cin>>N>>A;
    ll info[N];
    rep(i,N){
        cin>>info[i];
        info[i]-=A;
    }
    vvl ans(N+1,vl(2500));
    ans[0][1250]=1;
    rep(i,N){
        rep(j,2500){
            if(ans[i][j]){
                ans[i+1][j]+=ans[i][j];
                ans[i+1][j+info[i]]+=ans[i][j];
            }
        }
    }
    cout<<ans[N][1250]-1<<endl;
    return 0;
}