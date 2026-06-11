#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) rep2(i,0,n-1)
int MOD=1000000000+7;
int INF=1e6;
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    ll int n,m;
    cin>>n>>m;
    ll int t=0,s=0;
    ll int pre,temp;
    cin>>temp;
    rep(i,n-1){
        pre=temp;
        cin>>temp;
        ll int a=((i+1)*(n-1-i))%MOD;
        a=(a*(temp-pre))%MOD;
        t+=a;
        t%=MOD;
    }
    cin>>temp;
    rep(i,m-1){
        pre=temp;
        cin>>temp;
        ll int a=((i+1)*(m-i-1))%MOD;
        a=(a*(temp-pre))%MOD;
        s+=a;
        s%=MOD;
    }
    cout<<((t*s)%MOD);

    return 0;
}
