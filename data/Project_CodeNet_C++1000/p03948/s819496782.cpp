#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <map>
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
inline bool Yes(bool condition){ if(condition) PRINT("Yes"); else PRINT("No"); }
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
constexpr int nx[4] = {1,0,-1,0};
constexpr int ny[4] = {0,1,0,-1};
typedef pair<ll,ll> P;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n),l(n,INF),r(n,0);
    cins(all(a));
    l[0] = a[0];
    r[n-1] = a[n-1];
    rep(i,n-1){
        l[i+1] = min(l[i],a[i+1]);
        r[n-i-2] = max(r[n-i-1],a[n-i-2]);
    }
    ll max = 0;
    rep(i,n-1) chmax(max,r[i+1]-l[i]);
    ll ans = 0;
    map<ll,bool> done;
    rep(i,n-1){
        if (r[i+1]-l[i] == max && done[r[i+1]] == 0){
            ans++;
            done[r[i+1]] = 1;
        }
    }
    PRINT(ans);
}
