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
    ll n,x;
    cin >> n >> x;
    vi a(n);
    rep(i,n) cin >> a.at(i);
    vi b(n-1);
    rep(i,n-1) b.at(i) = a.at(i) + a.at(i+1);
    // 2連続でxを超えていたら後者を下げていく
    // 連続でxを超えていなかったらそのまま下げていく
    ll res = 0;
    rep(i,n-2){
        if(b.at(i)>x){
            ll eat = b.at(i)-x;
            if(a.at(i+1) >= eat){
                res += eat;
                b.at(i+1) -= eat;
            }else{
                res += eat;
                b.at(i+1) -= a.at(i+1);
            }
        }
    }
    // rep(i,n-1) cout << b.at(i) << endl;
    if(b.at(n-2)>x) res += b.at(n-2)-x;
    cout << res << endl;
}