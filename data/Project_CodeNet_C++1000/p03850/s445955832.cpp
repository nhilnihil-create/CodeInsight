#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d>>(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;


struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[i*2+1], node[i*2+2]);
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return -1000000000000000000;
        if(a <= l && r <= b) return node[k];
        ll vl = query(a, b, 2*k+1, l, (l+r)/2);
        ll vr = query(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};


struct LazySegmentTree2 {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree2(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 1000000000000000000;
        if(a <= l && r <= b) return node[k];
        ll vl = query(a, b, 2*k+1, l, (l+r)/2);
        ll vr = query(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  vll a(n);
  for(int i=0;i<n;i++){
    ll op = 1;
    if(i!=0){
      char c;std::cin >> c;
      if(c=='-') op = -1;
    }
    std::cin >> a[i];
    a[i] *= op;
  }

  // i時点での最大値 = a[i] + max(dp[j+1] - S[i+1:j])

  // 操作後、全区間に -a[i]を足す
  // -> 区間加算区間max

  LazySegmentTree seg(vll(n+1, 0));
  LazySegmentTree2 seg2(vll(n+1, 0));//最小値

  vll ans(n+1, 0);
  vll min_ans(n+1, 0);

  for(int i=n-1;i>=0;i--){

    if(a[i]<0) {
      ll q = seg.query(i+1, n+1);
      ll p = seg2.query(i+1, n+1);
      ans[i] =  a[i] + max({ans[i+1], q, -min_ans[i+1]});
      min_ans[i] = a[i] + min({min_ans[i+1], p, -q});
    }else{
      ans[i] = ans[i+1] + a[i];
      min_ans[i] = min_ans[i+1] + a[i];
    }

    seg.add(i, i+1, ans[i]);
    seg.add(i+1, n+1, a[i]);

    seg2.add(i, i+1, min_ans[i]);
    seg2.add(i+1, n+1, -a[i]);
    //seg2.add(i, i+1, a[i]);

    //for(int j=0;j<=n;j++) std::cout << seg.query(j, j+1) << (j==n?"\n":" ");
    //for(int j=0;j<=n;j++) std::cout << seg2.query(j, j+1) << (j==n?"\n":" ");
    //std::cout << ans[i] << " " << min_ans[i] << '\n';
  }

  std::cout << ans[0] << '\n';
  return 0;
}
