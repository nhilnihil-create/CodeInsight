#include <bits/stdc++.h>
struct LazySegmentTreeAddSum {
    int n;
    std::vector<long long> node, lazy;
    LazySegmentTreeAddSum(std::vector<long long> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        for(int i=0;i<sz;++i) {
            node[i+n-1] = v[i];
        }
        for(int i=n-2;i>=0;--i) {
            node[i] = node[i*2+1] + node[i*2+2];
        }
    }
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
    void add(int a, int b, long long x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2];
    }
    long long getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        long long vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        long long vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n, m; cin >> n >> m;
  vector<vector<P>> v(m+1);
  for(int i=0;i<n;++i) {
    int l, r; cin >> l >> r;
    v[r-l+1].push_back({l, r});
  }
  LazySegmentTreeAddSum st(vll(m+1));
  ll su = n;
  for(int i=1;i<=m;++i) {
    for(int j=0;j<(int)(v[i].size());++j) {
      su--;
      st.add(v[i][j].first, v[i][j].second + 1, 1);
    }
    int pos = 0;
    int ans = su;
    while(pos <= m) {
      ans += st.getsum(pos, pos+1);
      pos += i;
    }
    cout << ans << endl;
  }
}
