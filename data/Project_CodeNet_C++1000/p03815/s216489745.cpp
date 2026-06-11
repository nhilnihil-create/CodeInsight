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
    ll x;
    cin >> x;
    ll res = (x/11)*2;
    ll remain = x%11;
    if(remain==10) res += 2;
    if(remain==9) res += 2;
    if(remain==8) res += 2;
    if(remain==7) res += 2;
    if(remain==6) res += 1;
    if(remain==5) res += 1;
    if(remain==4) res += 1;
    if(remain==3) res += 1;
    if(remain==2) res += 1;
    if(remain==1) res += 1;
    cout << res << endl;
}