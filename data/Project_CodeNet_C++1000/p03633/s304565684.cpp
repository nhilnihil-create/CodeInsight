#include <bits/stdc++.h>
#include <cassert>
#include <numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;



ll gcd(ll a, ll b){
    if(a%b == 0){
        return(b);
    }else{
        return(gcd(b, a%b));
    }
}
 
ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    ll x=t[0];
    rep(i,n){
        x=lcm(x,t[i]);
    }
    cout << x << "\n";
    return 0;
}   