#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,inf=mod*mod*3ll;;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N,K;
ll a[5005];
bool dp[5005][5005];
bool check(ll in){
    //trueなら必要　falseなら不必要
    if(a[in]>=K) return true;
    ll penta=a[in];
    swap(a[in],a[N-1]);
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;
    if(a[0]<5003) dp[0][a[0]]=true;
    rep1(i,N){
        rep(k,5003){
            if(k-a[i]>=0){
                if(dp[i-1][k-a[i]]||dp[i-1][k]) dp[i][k]=true;
            }
            else{
                if(dp[i-1][k]) dp[i][k]=true;
            }
        }
    }
    for(ll y=K-penta;y<K;y++){
        if(dp[N-2][y]){
            swap(a[in],a[N-1]); 
            return true;
        }
    }
    swap(a[in],a[N-1]);
    return false;
}
bool isOK(ll index) {
    if(index<0) return true;
    if(index>N-1) return false;
    if(check(index)) return true;
    else return false;
}
ll bin_search(){
    ll ng=-1; 
    ll ok=N; 
    while (abs(ok-ng)>1) {
        ll mid=(ok+ng)/2;
        if (isOK(mid)) ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>K;
rep(i,N) cin>>a[i];
if(N==1){
    if(a[0]>=K) cout<<0<<endl;
    else cout<<1<<endl;
    return 0;
}
sort(a,a+N); 
ll ans=bin_search();
cout<<ans<<endl;

}
	
