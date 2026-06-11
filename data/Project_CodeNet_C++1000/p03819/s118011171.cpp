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

struct LazySegmentTree {
private:
    int n;
    vector<int> node, lazy;
    vector<bool> lazyFlag;

public:
    LazySegmentTree(vector<int> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            //node[k] = (r-l)*lazy[k]; // change
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[k*2+1] += lazy[k]/2; // change
                lazy[k*2+2] += lazy[k]/2; // change
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazy[k] = 0;
            lazyFlag[k] = false;
        }
    }

    void update(int a, int b, int x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            //lazy[k] = x;// change
            lazy[k] += (r-l)*x; //del
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    int find(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return vl+vr;
    }
};
int main(int argc, char const *argv[]) {
  ll n, m;std::cin >> n >> m;
  vvl lr = vv(n, 3, 0, ll);
  for(int i=0;i<n;i++){
    std::cin >> lr[i][1] >> lr[i][2];
    lr[i][0] = lr[i][2] - lr[i][1] + 1;
  }
  vector<int> c(m+1, 0);
  LazySegmentTree seg(c);
  sort(lr.begin(), lr.end());
  for(int i=1, j=0;i<=m;i++){
    while(j!=n&&lr[j][0]<=i){
      seg.update(lr[j][1], lr[j][2]+1, 1);
      j++;
    }
    ll ans = n - j;
    for(int j=1;j*i<=m;j++){
      ans += seg.find(j*i, j*i+1);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
