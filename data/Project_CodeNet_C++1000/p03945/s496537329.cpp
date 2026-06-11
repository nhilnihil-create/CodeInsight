#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
int64_t INF = 10010010010;
// int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;
// int64_t INF = 998244353;

vvi mem(21,vi(0));

ll getSalary(ll i){
    if(mem.at(i).size()==0) return 1;
    if(mem.at(i).size()==1) return 2*getSalary(mem.at(i).at(0))+1;
    ll maxS = -1;
    ll minS = INF;
    for(ll j:mem.at(i)){
        maxS = max(maxS, getSalary(j));
        minS = min(minS, getSalary(j));
    }
    return maxS + minS + 1;
}
int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    string s;
    cin >> s;
    // 切り替わる数を左右で比較
    ll res = 0;
    rep(i,s.size()-1) if(s.at(i)!=s.at(i+1)) res++;
    cout << res << endl;
}