#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll a[n],sum=0;
    for(ll i=0;i<n;i++)cin>>a[i],sum+=a[i];
    ll tot = (n*(n+1))/2;
    if(sum%tot)return cout<<"NO" , 0;
    ll k = sum/tot;
    //cout<<"K: "<<k<<endl;
    for(ll i=0;i<n;i++){
        ll diff = a[(i+1)%n] - a[i];
        ll val = k - diff;
        if(val>=0 && val%n==0)continue;
        return cout<<"NO" , 0;
    }
    cout<<"YES";
}
