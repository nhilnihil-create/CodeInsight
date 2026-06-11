#include<bits/stdc++.h>
using namespace std ;
#define ll long long


int main() {

    ll n  ,i ;
    cin >> n ;
    vector<ll>v(n) , a(n) , b(n) ;
    for (i = 0 ; i< n ;i++) cin >> v[i] ;
    a= v ;
    sort(a.begin(),a.end()) ;
    map<ll,ll>pos1 ,pos2 ;
    for ( i = 0 ; i< n ; i++) {
        pos1[a[i]] = i%2 ;
        pos2[v[i]] = i%2 ;
    }

    ll ans = 0 ;
    for (i = 0 ; i< n ; i++) {
        if (pos1[v[i]]!=pos2[v[i]]) ans++ ;
    }
    cout << ans/2 << endl ;




    return 0 ;
}
