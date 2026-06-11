#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll t[n],a[n];
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll h[n];
    memset(h,-1,sizeof(h));
    h[0]=t[0];
    h[n-1]=a[n-1];
    ll ans=1;
    for(int i=1;i<n-1;i++){
        if(t[i]!=t[i-1]){
            h[i]=t[i];
        }
        if(a[i]!=a[i+1]){
            h[i]=a[i];
        }
        if(h[i]==-1){
            ans*=min(a[i],t[i]);
            ans%=mod;
        }
    }
    ll num=h[0];
    for(int i=0;i<n;i++){
        if(i)num=max(h[i],num);
        if(num!=t[i]){
            cout<<0<<endl;
            return 0;
        }
    }
    num=h[n-1];
    for(int i=n-1;i>=0;i--){
        if(i!=n-1){
            num=max(h[i],num);
        }
        if(num!=a[i]){
            cout << 0<<endl;
            return 0;
        }
    }
    cout << ans<<endl;

    return 0;
}

