#include"bits/stdc++.h"
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define INF INT_MAX

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
    int k,s;
    cin>>k>>s;

    ll ans=0;
    rep(i,k+1){
        rep(j,k+1){
            if(s-i-j<=k&&s-i-j>=0){
                ++ans;
            }
        }
    }

    cout<<ans;
}


/*

*/