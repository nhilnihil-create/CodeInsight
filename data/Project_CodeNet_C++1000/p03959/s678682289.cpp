#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
ll MOD = 1e9+7;
ll INF = 1LL<<60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin>>n;
    vector<ll> t(n),a(n);
    rep(i,n)cin>>t[i];
    rep(i,n)cin>>a[i];
    vector<ll> lb1(n), ub1(n), lb2(n), ub2(n);
    rep(i,n){
        if(i==0){
            lb1[i]=t[i];
            ub1[i]=t[i];
            continue;
        }
        if(t[i]!=t[i-1]){
            lb1[i]=t[i];
            ub1[i]=t[i];
        }
        else{
            lb1[i]=1;
            ub1[i]=ub1[i-1];
        }
    }
    rep(j,n){
        ll i = n-j-1;
        if(i==n-1){
            lb2[i]=a[i];
            ub2[i]=a[i];
            continue;
        }
        if(a[i]!=a[i+1]){
            lb2[i]=a[i];
            ub2[i]=a[i];
        }
        else{
            lb2[i]=1;
            ub2[i]=ub2[i+1];
        }
    }
    ll ans = 1;


    rep(i,n){
        ll lb = max(lb1[i],lb2[i]);
        ll ub = min(ub1[i],ub2[i]);
        if(lb>ub){
            ans = 0;
            break;
        }
        ans = (ans*(ub-lb+1))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}