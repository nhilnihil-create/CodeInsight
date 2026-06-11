#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll INF = 1e15;
struct SegmentTree {
private:
    ll n;
    vector<ll> node;

public:
    SegmentTree(vector<ll> v) {
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(ll i=0; i<sz; i++) node[i+n-1] = v[i];
        for(ll i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(ll x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmin(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main(){
    ll n, x; cin>>n>>x;
    vector<ll> a(n);
    rep(i, n) cin>>a[i];
    SegmentTree seg(a);
    ll res=1e15;
    for(ll i=0; i<n; i++){
        ll tmp = x*i;
        rep(j, n){
            if(j<i){
                tmp += min(seg.getmin(0, j+1), seg.getmin(n+j-i, n));
            }else{
                tmp += seg.getmin(j-i, j+1);
            }
        }
        chmin(res, tmp);
    }
    cout<<res<<endl;
    return 0;
}