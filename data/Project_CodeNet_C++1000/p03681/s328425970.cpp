#include "bits/stdc++.h"
#include "bitset"


#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define pai pair<int,int> 
#define For(i,a,n) for(i=a;i<n;i++)
#define all(ar) ar.begin(),ar.end() 
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;
const ll mod = 1000000007;

ll fac(ll a){
    ll k = 1;
    for(ll n = 1; n<= a; n++){
        k = ((k%mod) * n) % mod;
    }
    return k;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    //*/
    ll a,b; cin>>a>>b;
    if(abs(a-b) > 1) cout<<0;
    else{
        ll ans = (fac(a) * fac(b)) % mod;
        if(a%2 == b%2) ans = (ans * 2 ) % mod;
        cout<<ans; 
    }
    return 0;
}
