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
#include <unordered_map>
#include <numeric>
#include <functional>
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
    string ans = "",k = " ";
    for (auto i = start;i != goal;i++) ans += to_string(*i)+k;
    if (!ans.empty()) ans.pop_back();
    PRINT(ans);
}
ll gcd(ll a, ll b) {
    return a ? gcd(b%a,a) : b;
}
const ll INF = 1e15;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
typedef pair<ll,ll> P;
const ll MAX = 200010;
constexpr ll nx[8] = {1,0,-1,0,-1,-1,1,1};
constexpr ll ny[8] = {0,1,0,-1,-1,1,-1,1};
class SegTree{
    private:
        ll n;
        vector<ll> node;
    public:
        SegTree(vector<ll> v){
            ll sz = v.size();
            n = 1;
            while(n < sz) n *= 2;
            node.resize(2*n+1,INF);
            rep(i,sz) node[i+n-1] = v[i];
            for(int i = n-2;i >= 0;i--) node[i] = min(node[2*i+1],node[2*i+2]);
        }
        void update(ll x,ll val){
            x += (n-1);
            node[x] = val;
            while(x > 0){
                x = (x-1)/2;
                node[x] = min(node[2*x+1],node[2*x+2]);
            }
        }
        ll query(ll a,ll b,ll k = 0,ll l = 0,ll r = -1){
            if (r < 0) r = n;
            if (r <= a || b <= l) return INF;
            if (a <= l && r <= b) return node[k];
            ll vl = query(a,b,2*k+1,l,(l+r)/2);
            ll vr = query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    cins(all(a));
    SegTree m(a);
    ll ans = INF,c = 0;
    rep(i,n){
        c = x*i;
        rep(j,n){
            if (j-i >= 0){
                c += m.query(j-i,j+1);
            }
            else{
                c += min(m.query(0,j+1),m.query(n-(i-j),n));
            }
        }
        chmin(ans,c);
    }
    PRINT(ans);
}
