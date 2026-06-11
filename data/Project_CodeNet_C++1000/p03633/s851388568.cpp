#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define umap unordered_map<ll, ll>
using namespace std;

ll gcd(ll x, ll y){
    if(y == 0){
        return x;
    }
    return gcd(y, x%y);
}

ll lcm(ll x, ll y){
    return x*(y/gcd(x, y));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, a, ans = 0;
    cin >> n;
    vll x;
    
    for(ll i=0; i<n; i++){
        cin >> a;
        x.push_back(a);
    }
    
    ans = x[0];
    for(ll i=1; i<n; i++){
        ans = lcm(ans, x[i]);
    }
    
    cout << ans << endl;
    return 0;
}