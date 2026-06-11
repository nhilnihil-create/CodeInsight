#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
pair< ll , ll > a[505];
ll ans[505*505];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
        ans[a[i].first]=a[i].second;
    }
    sort(a+1,a+n+1);
    ll now=1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<a[i].second;j++){
            while(ans[now] && now<=n*n)now++;
            if(now>n*n)return cout<<"No"  , 0;
            ans[now]=a[i].second;
        }
        if(now > a[i].first )return cout<<"No" , 0;
    }
    now=n*n;
    for(ll i=n;i>=1;i--){
        for(ll j=a[i].second+1;j<=n;j++){
            while(ans[now] && now>=0 )now--;
            ans[now]=a[i].second;
        }
        if(now<a[i].first)return cout<<"No" , 0;
    }

    for(ll i=1;i<=n*n;i++)if(!ans[i])return cout<<"No" , 0;

    cout<<"Yes\n";
    for(ll i=1;i<=n*n;i++)cout<<ans[i]<<" ";
}

