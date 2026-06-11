#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vll vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

//-------------------------------------------------------------------
#define P 1000000007
#define N_MAX 2000000
typedef long long int ll;
ll fac[N_MAX+1];
ll inv[N_MAX+1];
ll finv[N_MAX+1];

ll comb(ll n, ll k){
    return (((fac[n]*finv[n-k])%P)*finv[k])%P;
}

void init(){
    fac[0] = finv[0] = fac[1] = finv[1] = inv[1] = 1;
    for(int i = 2; i <= N_MAX; i++){
        fac[i] = (fac[i-1]*i)%P;
        inv[i] = ((-(P/i)*inv[P%i])%P+P)%P;
        finv[i] = (finv[i-1]*inv[i])%P;
    }
}
ll pp(ll a, ll b){
  return (a * b)%P;
}
struct LazySegmentTree {
private:
    int n;
    vector<int> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (ll)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
    void lazyEvaluate(ll k, ll l, ll r) {
        if(lazyFlag[k]) {
            //node[k] = (r-l)*lazy[k]; // change
            node[k] = (node[k] +lazy[k])%P;
            if(r - l > 1) {
                lazy[k*2+1] = (lazy[k*2+1] +  pp(lazy[k], inv[2]))%P; // change
                lazy[k*2+2] = (lazy[k*2+2] +  pp(lazy[k], inv[2]))%P; // change
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazy[k] = 0;
            lazyFlag[k] = false;
        }
    }

    void update(ll a, ll b, ll x, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            //lazy[k] = x;// change
            lazy[k] =  (lazy[k] + ((r-l)*x)%P)%P; //del
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = (node[2*k+1] + node[2*k+2])%P;
        }
    }

    ll find(ll a, ll b, ll k=0, ll l=0, ll r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = find(a, b, 2*k+1, l, (l+r)/2);
        ll vr = find(a, b, 2*k+2, (l+r)/2, r);
        return (vl+vr)%P;
    }
};
int main(int argc, char const *argv[]) {
  init();
  ll n;std::cin >> n;
  LazySegmentTree seg(vector<ll> (n+4, 0));
  seg.update(0, 1, 1);
  std::vector<ll> dp(n+1);
  for(int i=0;i<n;i++){
    ll tmp = seg.find(i, i+1);
    dp[i] = tmp;
    seg.update(i+3, n+4, tmp);
    seg.update(i+1, i+2, tmp);
    //std::cout << dp[i] << '\n';
  }
  ll u = pp(dp[n-1], n);
  ll t = 0, k = 0;
  for(int i=0;i<n-1;i++) t = (t + pp(dp[i],pp((n-1),(n-1))))%P;
  for(int i=0;i<n-1;i++) k = (k + pp(dp[i], min(n-1, (ll)i+2)))%P;
  std::cout << (u+t+k)%P << '\n';
  return 0;
}
