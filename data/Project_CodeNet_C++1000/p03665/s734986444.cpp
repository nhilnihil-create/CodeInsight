# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
typedef long long ll;
ll n,p,arr[55],memo[55][1005];
ll f(ll idx,ll sum){
    if(idx==n+1){
        if(sum==p) return 1;
        return 0;
    }
    if(memo[idx][sum]!=-1) return memo[idx][sum];
    ll res=f(idx+1,sum)+f(idx+1,(sum+arr[idx])%2);
    return memo[idx][sum]=res;
}
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>p;
    memset(memo,-1,sizeof(memo));
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]%=2;
    }
   ll ans=f(1,0);
   cout<<ans<<endl;
}