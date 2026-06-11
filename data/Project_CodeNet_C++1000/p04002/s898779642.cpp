#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)



int main(){
    ll h,w,n;cin>>h>>w>>n;
    map<pair<ll,ll>,ll> m;
    ll a[n],b[n];
    rep(i,n){
        cin>>a[i]>>b[i];
        --a[i];--b[i];
        m[make_pair(a[i],b[i])]=1;
    }
    ll ans[10];
    memset(ans,0,sizeof(ans));
    ans[0]=(h-2)*(w-2);
    rep(i,n){
        rep(j,a[i]-2,a[i]+1){
            if(j<0||(j+2)>=h)continue;
            rep(k,b[i]-2,b[i]+1){
                if(k<0||(k+2)>=w)continue;
                int ctr=0;
                rep(y,j,j+3){
                    rep(x,k,k+3){
                        if(m[make_pair((ll)y,(ll)x)]==1)ctr++;
                    }
                }
                ans[ctr]++;
            }
        }
    }
    rep(i,9)ans[0]-=ans[i+1]/(i+1);
    rep(i,10){
        if(i)cout<<ans[i]/i<<endl;
        else cout<<ans[i]<<endl;
    }
}


    