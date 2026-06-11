#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define era(t) t.erase(unique(be(t)),t.end())
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;
const ll mod=1000000007,mod9=1000000009;
template <class T>inline T lcm(T a,T b){return (a*b/__gcd(a,b));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll a[n],b[n+1],c[n+1];
    b[0]=c[0]=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
        c[i+1]=c[i]+max(0ll,a[i]);
    }
    ll ans=0;
    for(ll i=0;i<=n-k;i++){
        ans=max(ans,c[n]-c[i+k]+c[i]+max(0ll,b[i+k]-b[i]));
    }
    cout <<ans<<endl;
    return 0;
}


