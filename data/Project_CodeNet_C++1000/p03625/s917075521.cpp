#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
#define P pair<int, int>

int main () {
    ll n ;
    cin >> n ;
    ll a[n] ;
    for(ll i = 0 ; i < n ; i++ ){
        cin >> a[i] ;
    }

    sort(a , a + n) ;
    ll c , b ;
    c = 0 ;
    b = 0 ;
    ll count = 1 ;
    for(ll j = 0 ; j < n - 1 ; j++ ){
        if(a[j] == a[j + 1] ){
            count ++ ;
            if(count % 2 == 0){
           if(c <= b){
               if(c < a[j]){
               c = a[j] ;
               }
           }else{
               if(b < a[j]){
               b = a[j] ;
               }
           }
            }
        }else{
            count = 1 ;
        }
    }


    cout << b * c << endl;
    return 0 ;
}

 
