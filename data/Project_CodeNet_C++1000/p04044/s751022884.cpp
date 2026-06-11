/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define hcf __gcd

bool is_prime(ll n){
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i*i<=n;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen ("C:\\Users\\Animesh\\Desktop\\i.txt", "r", stdin);
    //freopen ("C:\\Users\\Animesh\\Desktop\\o.txt", "w", stdout);
#endif
    int n; cin>>n;
    int l; cin>>l;
    vector<string> s(n); for(auto& it:s) cin>>it;
    sort(s.begin(),s.end());
    for(auto it:s)
        cout<<it;

return 0;
/* check for bounds before submitting */
}
