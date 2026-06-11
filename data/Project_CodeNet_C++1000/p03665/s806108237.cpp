#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n, p;
    cin >> n >> p;
    vector<unsigned ll> even, odd;
    rep(i, n){
        ll a;
        cin >> a;
        if(a%2) odd.push_back(a);
        else even.push_back(a);
    }
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));
    rep(i, v.size()) v[i][0] = v[i][i] = 1;
    rep(i, n){
        rep(j, i){
            v[i+1][j+1] = v[i][j] + v[i][j+1];
        }
    }
    ll even_sum = 0;
    rep(i, even.size()+1) even_sum += v[even.size()][i];
    ll odd_sum = 0;
    rep(i, odd.size()+1){
        if(i%2 == p) odd_sum += v[odd.size()][i];
    }
    cout << even_sum * odd_sum << endl;
    return 0;
}
