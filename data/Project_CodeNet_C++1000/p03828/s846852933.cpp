#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;
// int64_t INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    vi a(1001);
    // 2^a*3^b*...っていう形にして、(a+1) * (b+1) * ...
    for(ll i=2; i<n+1; i++){
        ll k=i;
        for(ll j=2; j<i+1; j++){
            while(k%j==0){
                a.at(j)++;
                k = k/j;
            }
        }
    }
    ll res = 1;
    rep(i,a.size()){
        if(a.at(i)!=0){
            res *= a.at(i)+1;
            res %= INF;
        }
    }
    cout << res << endl;
}