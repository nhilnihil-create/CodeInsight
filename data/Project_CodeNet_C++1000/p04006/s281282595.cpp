#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2005;
ll a[N],b[N],n,x;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>x;
    for(ll i=0;i<n;i++)cin>>a[i],b[i]=a[i];
    ll ans = LLONG_MAX;
    for(ll i=0;i<n;i++){
        ll cur = i*x;
        for(ll j=0;j<n;j++){
            b[j] = min(b[j] , a[(j-i+n)%n]);
            cur+=b[j];
        }
        ans=min(ans , cur);
    }
    cout<<ans;
}

