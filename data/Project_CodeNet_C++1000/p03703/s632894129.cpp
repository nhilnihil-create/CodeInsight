#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=3.14159265358979323846;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

struct BinaryIndexedTree {
    vector<ll> data;
    BinaryIndexedTree(int size): data(size+1,0) {
        
    }
    int n=sz(data);
    void add(int a,ll w) {
        for(int i=a; i<=n; i+=(i&-i)) data[i] += w;
    }
    ll sum(int a) {
        int ret=0;
        for(int i=a; i>0; i-=(i&-i)) ret+=data[i];
        return ret;
    }
};


int main() {
    ll n,k;
    cin>>n>>k;
    vector<ll> vec(n+1,0);
    rep(i,n) {
        ll a;
        cin>>a;
        a-=k;
        vec[i+1]=vec[i]+a;
    }
    
    vector<ll> vals;
    rep(i,n+1) vals.push_back(vec[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)),vals.end());
    
    rep(i,n+1) {
        int x=lower_bound(all(vals),vec[i])-vals.begin()+1;
        vec[i]=x;
    }
    
    BinaryIndexedTree BIT(300000);
    ll ans=0;
    rrep(i,n+1) {
        if(i!=n) ans+=(ll)((n-i)-BIT.sum(vec[i]-1));
        BIT.add(vec[i],1);
    }
    cout<<ans<<endl;
    
}
