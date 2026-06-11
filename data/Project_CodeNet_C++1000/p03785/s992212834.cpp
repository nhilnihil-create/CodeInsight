#include"bits/stdc++.h"
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007

using namespace std;
typedef long long ll;

template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) {
        return(b);
    }
    else {
        return(gcd(b, a % b));
    }
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll>t(n);
    rep(i,n){
        cin>>t[i];
    }
    sort(ALL(t));
    ll ans=0;
    ll time=t[0],next=0;
    ll m=0;
    while(next<n){
        ++ans;
        m=0;
        while(next<n&&time+k>=t[next]&&m<c){
            // cout<<t[next]<<" ";
            ++next;
            ++m;
        }
        // cout<<endl;
        time=t[next];
    }
    cout<<ans;
}
