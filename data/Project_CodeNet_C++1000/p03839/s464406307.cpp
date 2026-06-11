#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    ll sum=0;
    rep(i,N){
        cin >> a[i];
        if (a[i]>0){
            sum+=a[i];
        }
    }
    ll countn=0,countp=0;
    rep(i,K){
        if (a[i]<0){
            countn+=a[i];
        }
        else {
            countp+=a[i];
        }
    }
    ll ans=0;
    chmax(ans,sum+countn);
    chmax(ans,sum-countp);
    rep(i,N-K){
        if (a[i]<0){
            countn-=a[i];
        }
        else {
            countp-=a[i];
        }
        if (a[K+i]<0){
            countn+=a[K+i];
        }
        else {
            countp+=a[K+i];
        }
        chmax(ans,sum+countn);
        chmax(ans,sum-countp);
    }
    cout << ans << endl;
}