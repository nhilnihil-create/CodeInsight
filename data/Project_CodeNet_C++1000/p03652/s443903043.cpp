#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=310;
ll a[N][N],mark[N],freq[N];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,m;cin>>n>>m;
    ll ans = N;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(ll k=1;k<=m;k++){
        memset(freq,0,sizeof(freq));
        for(ll i=1;i<=n;i++){
            ll j=1;
            for(;mark[a[i][j]]==1;j++);
            freq[a[i][j]]++;
        }
        ll maxx=0,maxi;
        for(ll i=1;i<=m;i++){
            if(freq[i]>maxx){
                maxx=freq[i];
                maxi=i;
            }
        }

        ans=min(ans , maxx);
        mark[maxi]=1;
    }

    cout<<ans;
}

