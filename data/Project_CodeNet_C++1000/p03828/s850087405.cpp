#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

map<ll, ll> prime_factor(ll n){
    map<ll, ll> mp;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            mp[i]++;
            n /= i;
        }
    }
    if(n != 1)mp[n]++;
    return mp;
}

int main() {
    ll n, ans = 1;
    cin >> n;
    vector<ll> num(n+1);
    for(int i = 2; i <= n; i++){
        for(auto p : prime_factor(i)){
            while(p.second--)num[p.first]++;
        }
    }
    rep(i, n+1){
        if(num[i] > 0)ans = (ans * (num[i]+1)) % mod;
    }
    cout << ans << endl;
}      