#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;
ll comb(ll a,ll b){
    ll com=1;
    while(a>0){
        com*=a;
        com%=MOD;
        a--;
    }
    while(b>0){
        com*=b;
        com%=MOD;
        b--;
    }
    return com;
}
int main() {
    ll N,M; cin>>N>>M;
    if(abs(N-M)>1){
        cout<<0;
        return 0;
    }
    ll ans=0;
    if(N==M){
        ans=comb(N,M)*2;
        ans%=MOD;
    }
    else{
        ans=comb(N,M);
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}