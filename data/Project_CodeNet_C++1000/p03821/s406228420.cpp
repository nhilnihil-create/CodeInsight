#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;++i)
#define END(x) (*(x.end()-1))

using namespace std;
typedef long long ll;


template<typename T>
T gcd(T a, T b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

template<typename T>
T lcm(T a,T b){
    return a/gcd(a,b)/b;
}

int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    ll ans=0;
    for(ll i=n-1;i>=0;--i){
        a[i]+=ans;
        if(a[i]%b[i]!=0){
            ans+=b[i]-a[i]%b[i];
        }
    }
    cout<<ans;
}
/*

*/
