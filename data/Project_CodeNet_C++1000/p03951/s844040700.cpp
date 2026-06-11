#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    ll res = 2*n;
    rep(i,n){
        string sub = s.substr(i);
        rep(j,sub.size()){
            if(sub.at(j)!=t.at(j)) break;
            if(j==sub.size()-1) res = 2*n-sub.size();
        }
        if(res!=2*n) break;
    }
    cout << res << endl;
}