#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
struct edge{ll to,cost;};
const int inf = 1<<28;
const ll INF = 1LL<<53;
const int COMBMAX = 500005;
const ll MOD = 1e9+7;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;++i)
#define repf(i,n) for(int i=0;i<=n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define eachdo(v, e) for(const auto& e : v)
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance(v.begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance(v.begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n,ll mod=MOD){ll res=1;while(n>0){if(n&1)res=res*a%mod;a=a*a%mod;n>>=1;}return res;}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v,a)-lower_index(v,a);} 
template<class T> bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
template<class T> void debug2(T v){rep(i,v.size()){rep(j,v[i].size())cout<<v[i][j]<<" ";cout<<endl;}}
template<class T> void rdv(T &v){rep(i,v.size())cin>>v[i];}
template<class T> void rdvv(T &v){rep(i,v.size()){rep(j,v[i].size())cin>>v[i][j];}}
// multimap
// mmap.emplace(key,value);
// auto ngw = list.equal_range("");
// for(auto e = ngw.first; it != ngw.second ; ++e)

struct SegmentTree{
private:
    ll unit = 0;
    ll op(ll a,ll b){return a + b;}
    ll n;
    vector<ll> node;

public:
SegmentTree(vector<ll> v){
    ll sz = (ll)v.size();
    n = 1;while(n<sz) n *= 2;
    node.resize(2*n-1,unit);
    for(ll i=0;i<sz;i++) node[i+n-1]=v[i];
    for(ll i=n-2;i>=0;i--) node[i]=op(node[2*i+1],node[2*i+2]);
}

    void update(ll x,ll val){
        x += n-1;
        node[x] = val;
        while(x>0){
            x = (x-1)/2;
            node[x] = op(node[2*x+1],node[2*x+2]);
        }
    }

    ll query(ll a,ll b,ll k = 0,ll l = 0,ll r = -1){
        if (r<0) r = n;
        if (r<=a || b<=l) return unit;
        if (a<=l && r<=b) return node[k];
        ll vl = query(a,b,2*k+1,l,(l+r)/2);
        ll vr = query(a,b,2*k+2,(l+r)/2,r);
        return op(vl,vr);
    }
};

int main(){
    ll N; cin >> N;
    vl a(N); rdv(a);
    SegmentTree st(a);
    ll ans = INF;
    rep(i,N-1){
        chmin(ans,abs(st.query(0,i+1) - st.query(i+1,N)));
    }
    cout << ans << endl;
    return 0;
}