#include <iostream>
#include <iomanip>
#include <algorithm>
#include <complex>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline void Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
template<class itr> void cins(itr first,itr last){
    for (auto i = first;i != last;i++){
        cin >> (*i);
    }
}
template<class itr> void array_output(itr start,itr goal){
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e10;
const ll MOD = 100000000;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
const ll MAX = 100;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    cins(all(a));
    vector<vector<bool>> down(n,vector<bool>(k+1,0)),up(n,vector<bool>(k+1,0));
    rep(i,n) down[i][0] = up[i][0] = 1;
    rep(i,n-1){
        rep(j,k+1){
            if (down[i][j]){
                down[i+1][j] = down[i+1][min(k,j+a[i])] = 1;
            }
            if (up[i][j]){
                up[i+1][j] = up[i+1][min(k,j+a[n-i-1])] = 1;
            }
        }
    }
    vector<vector<int>> l(n),r(n);
    rep(i,n){
        rep(j,k+1){
            if (down[i][j]) l[i].push_back(j);
            if (up[i][j]) r[i].push_back(j);
        }
    }
    rep(i,n){
        l[i].push_back(INF);
        r[i].push_back(INF);
    }
    int ans = 0;
    rep(i,n){
        if (a[i] >= k) continue;
        bool ok = 1;
        int c = k-a[i];
        rep(j,l[i].size()-1){
            int s = *lower_bound(all(r[n-i-1]),c-l[i][j]);
            if (s+l[i][j] < k) ok = 0;
        }
        if (ok) ans++;
    }
    PRINT(ans);
}
