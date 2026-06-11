#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

int main(){

    ll n;
    cin >> n;
    map<ll, ll> mp;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        if(mp[a]) mp[a] = 0;
        else mp[a]++;
    }
    ll ans = 0;
    for(auto iter : mp){
        if(iter.second == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
