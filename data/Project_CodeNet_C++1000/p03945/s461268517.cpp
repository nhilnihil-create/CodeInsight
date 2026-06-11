#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;++i)
#define END(x) (*(x.end()-1))
#define INF INT_MAX / 2

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
    return a/gcd(a,b)*b;
}

int main(void){
    string s;
    cin>>s;
    vector<char>c;
    ll ans=0;
    rep(i,s.length()-1){
        if(s[i]!=s[i+1]){
            ++ans;
        }
    }
    cout<<ans;
}
/*

*/
