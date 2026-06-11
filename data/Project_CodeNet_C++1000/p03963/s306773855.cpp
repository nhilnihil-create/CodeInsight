#include "bits/stdc++.h"

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
#define mod (int)1e9 + 7
#define For(i,a,n) for(i=a;i<n;i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;

ll exp(ll a,ll b){
    if(b == 0) return 1;
    ll tans = exp(a*a,b/2);
    if(b % 2) tans *= a;
    return tans;
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
    ll n,k;
    cin>>n>>k;
    cout<<k * exp(k-1,n-1);
    return 0;
}