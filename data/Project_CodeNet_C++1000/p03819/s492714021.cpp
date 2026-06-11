/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

ll l[300010], r[300010];
struct AddLazySegmentTree {
private:
    ll n;
    vector<ll> node, lazy;

public:
    AddLazySegmentTree(vector<ll> v) {
        ll sz = (ll)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(ll i=0; i<sz; i++) node[i+n-1] = v[i];
        for(ll i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(ll k, ll l, ll r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,N) cin >> l[i] >> r[i];
    ll cnt = 0;
    vector<lpair> lp;
    rep(i,0,N) lp.push_back({l[i], r[i]});
    sort(lp.begin(), lp.end(), [](lpair l1, lpair l2){
        return l1.second - l1.first < l2.second - l2.first;
    });
    rep(i,0,N){
        l[i] = lp[i].first;
        r[i] = lp[i].second;
    }
    vector<ll> v(M+1, 0);
    AddLazySegmentTree sg(v);

    ll ans[300010] = {};
    ans[1] = N;
    ll idx = 0;
    rep(i,2,M+1){
        while(idx < N){
            if(r[idx] - l[idx] + 1 < i){
                sg.add(l[idx], r[idx]+1, 1);
                idx++;
            }else{
                break;
            }
        }
        ans[i] = N - idx;
        for(ll j = i; j <= M; j += i){
            ans[i] += sg.getsum(j, j+1);
        }
    }
    rep(i,1,M+1) print(ans[i]);
    

}