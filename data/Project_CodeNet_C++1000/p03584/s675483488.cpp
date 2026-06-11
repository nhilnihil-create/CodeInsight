#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

const ll mod=1e9+7;
const ll inf=1ll<<60;

/*---------------------*/

ll n,k,ans,num;
vector<ll> a,b;

int main(){
    cin>>n>>k;
    a.resize(n);
    b.resize(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        if((k&a[i])==a[i])ans+=b[i];
    }
    rep(i,31){
        if((k>>i)&1==1){
            ll K=k;
            K|=(1<<i)-1;
            K-=(1<<i);
            num=0;
            rep(j,n){
                if((K&a[j])==a[j]){
                    num+=b[j];
                }
            }
            chmax(ans,num);
        }
    }

    cout<<ans<<endl;
}