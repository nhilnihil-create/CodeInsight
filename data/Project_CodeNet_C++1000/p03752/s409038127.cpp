#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
signed main(){
    int N,K;
    cin>>N>>K;
    vint A(N);
    rep(i,N)cin>>A[i];
 
    int ans=LLONG_MAX;
    rep(i,1<<N){
        vint v;
        rep(j,N)if(i>>j&1)v.pb(j);
        if(v.size()!=K)continue;
        int cost=0;
        int pre=-1;
        for(int j=0;j<v.size();j++){
            int ma=pre;
            for(int k=(j?v[j-1]:0);k<v[j];k++)chmax(ma,A[k]);
            cost+=max(0ll,ma-A[v[j]]+1);
            pre=max(ma+1,A[v[j]]);
        }
        chmin(ans,cost);
    }
    cout<<ans<<endl;
    return 0;
}