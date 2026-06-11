#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

signed main(){
    string A;
    cin >> A;
    ll len = A.length();
    map<char, ll> mp;
    for(auto a : A) mp[a]++;
    ll ans = len * (len - 1) / 2 + 1;
    for(auto p : mp){
        ans -= p.second * (p.second - 1) / 2;
    }
    PRINT(ans);
    return 0;
}