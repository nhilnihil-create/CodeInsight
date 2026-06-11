#include<bits/stdc++.h>
using namespace std ;
#define ll long long


int main() {

    ll n  ,i ;
    cin >> n ;
    vector<ll>v(n) , a(n) , b(n) ;
    for (i = 0 ; i< n ;i++) cin >> v[i] ;
    for ( i = 1 ; i<= n ;i++) {
        a[i-1] = 25000 * (i) ;
        b[n-i] = a[i-1] ;
    }

    for ( i = 0 ; i < n ;i++) {
        b[v[i]-1]+=i ;
    }
    for ( i = 0 ; i< n ;i++) cout << a[i] << " " ;
    cout << endl ;
    for (i  = 0 ; i< n; i++) cout << b[i] << ' ' ;


    return 0 ;
}
