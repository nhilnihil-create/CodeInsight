#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <map>
#include <bitset>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
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
    string ans = "";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+" ";
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
constexpr const ll INF = 1e15;
constexpr const ll MOD = 1000000007;
constexpr const ll MAX = 15;
constexpr int nx[4] = {1,0,-1,0};
constexpr int ny[4] = {0,1,0,-1};
typedef pair<ll,ll> P;
vector<vector<ll>> Next(string &s){
    int n = s.size();
    vector<vector<ll>> res(n+1, vector<ll>(26, n));
    for (int i = n-1; i >= 0; --i) {
        rep(j,26) res[i][j] = res[i+1][j];
        res[i][s[i]-'a'] = i;
    }
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> next = Next(s);
    vector<ll> dp(n+1,INF);
    vector<char> re(n+1,'a');
    dp[n] = 1;
    for(ll i = n-1;i >= 0;i--){
        rep(j,26){
            if (next[i][j] >= n){
                if (dp[i] > 1){
                    dp[i] = 1;
                    re[i] = 'a'+j;
                }
            }
            else if(chmin(dp[i],dp[next[i][j]+1]+1)){
                re[i] = 'a'+j;
            }
        }
    }

    string ans = "";
    ll index = 0;
    while(index <= n){
        ans += re[index];
        index = next[index][re[index]-'a']+1;
    }

    PRINT(ans);
}
