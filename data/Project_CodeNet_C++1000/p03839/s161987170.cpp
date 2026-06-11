#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,k,ans,a[N],best[N],sum[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        best[i]=best[i-1];
        if(a[i]>0)best[i]+=a[i];
    }
    for(ll i=1;i+k-1<=n;i++){
        ll r = i+k-1;
        ans = max(ans , max(sum[r]-sum[i-1],0ll) + best[i-1] + best[n]-best[r]);
    }
    cout<<ans;
}

