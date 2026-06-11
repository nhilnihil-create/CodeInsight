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
    vi a(n);
    rep(i,n) cin >> a.at(i);
    // 絶対値の差が渡されるから、2パターンの配置先が決まる
    // 2パターンの配置先の組み合わせを考える
    ll res = 1;
    rep(i,n/2) res *= 2, res %= INF;
    // 偶数
    if(n%2==0){
        vi ve(n/2,0);
        rep(i,n) ve.at(a.at(i)/2)++;
        rep(i,ve.size()-1){
            if(ve.at(i)>2){
                res = 0;
                break;
            }
        }
    }
    // 奇数
    if(n%2==1){
        vi vo(n/2+1,0);
        rep(i,n) vo.at(a.at(i)/2)++;
        // rep(i,vo.size()-1) cout << "i:" << i << " vo.i:" << vo.at(i) << endl;
        rep(i,vo.size()-1){
            if(vo.at(i)>2 || vo.at(0)>1){
                res = 0;
                break;
            }
        }
    }
    cout << res << endl;
}