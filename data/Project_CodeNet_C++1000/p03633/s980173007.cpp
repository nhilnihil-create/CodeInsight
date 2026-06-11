#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
const ll MOD=100000007;
const ll INF=1000000101001;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll nlcm(vector<ll> numbers){
    ll res;
    res=numbers[0];
    for (ll i = 1; i < numbers.size(); i++) {
        res = lcm(res, numbers[i]);
    }
     return res;
}
int main(){
    ll n;cin>>n;
    vector<ll> t(n);
    rep(i,n){
     cin>>t[i];
    }
    ll ans=0;
    ans=nlcm(t);
    cout << ans << endl;
}