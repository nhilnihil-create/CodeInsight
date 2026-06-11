#include<iostream>
using namespace std ;
#define  ll long long int 
#define pb push_back 
#include<bits/stdc++.h>

int main()
{
    ll n ;
    cin >> n ;
vector<ll> arr;
for( ll i= 0 ; i < 2*n ;i++) {
    ll  k ;
    cin>> k ; 
    arr.pb(k );
}
sort(arr.begin() , arr.end()) ;
ll sum = 0;
for( ll i=0 ; i< n ;i++ )
{
    sum+= min(arr[2*i] , arr[2*i+1]) ;
    
}
cout <<sum ;
return  0 ;
}
