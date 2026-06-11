#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    pair<ll,ll> a[n];for(ll i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
    sort(a,a+n);
    ll ans = 0;
    for(ll i=0;i<n;i++)if(a[i].second%2 != i%2)ans++;
    cout<<ans/2;
}

