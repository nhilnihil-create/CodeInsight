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
    string s;
    cin >> n >> s;
    // 最も手前に(をつける
    // 最も後ろに)をつける
    // cout << '(' + 0 << endl; // 40
    // cout << ')' + 0 << endl; // 41
    // start: 頭に(をつける必要のある個数
    // end: 尻尾に)をつける必要のある個数
    ll start=0 ,end=0;
    rep(i,n){
        if(s.at(i)=='(') end++;
        if(end!=0 && s.at(i)==')') end--;
    }
    for(ll i=n-1; i>=0; i--){
        if(s.at(i)==')') start++;
        if(start!=0 && s.at(i)=='(') start--;
    }
    string res = "";
    rep(i,start) res += "(";
    res += s;
    rep(i,end) res += ")";
    cout << res << endl;
}