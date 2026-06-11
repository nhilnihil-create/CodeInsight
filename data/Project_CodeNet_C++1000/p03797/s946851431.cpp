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

    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    if(m >= n*2){
        ans += n;
        m -= 2*n;
        n = 0;
        if(m < 0) m = 0;
        ans += m/4;
    }
    else{
        ans += m/2;
    }
    cout << ans << endl;

    return 0;
}
