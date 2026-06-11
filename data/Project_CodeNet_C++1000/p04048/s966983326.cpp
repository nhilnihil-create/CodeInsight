#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll n, ll x){
    if(x==0){
        return n;
    }
    else{
        return gcd(x,n%x);
    }
}
int main(void){
    ll n;
    cin>>n;
    ll x;
    cin>>x;
    ll val=gcd(n,x);
    cout<<3*(n-val);
}
