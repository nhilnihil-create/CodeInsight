#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
 
template <typename T>
class SegTree{
  using F = function<T(T,T)>;
  int n; T uni; F f;
  vector<T> dat;
  T query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return uni;
    if(a <= l && r <= b) return dat[k];
    T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
    T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
    return f(vl,vr);
  }
public:
  SegTree(int _n, F f, T uni) : f(f), uni(uni) {
    n = 1;
    while(n < _n) n *= 2;
    dat = vector<T>(2*n-1,uni);
  }
  void update(int k, T a) {
    k += n-1;
    dat[k] += a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = f(dat[2*k+1], dat[2*k+2]);
    }
  }
  T query(int a, int b) {
    return query_sub(a, b, 0, 0, n);
  } // [a,b)
};
 
int main(){
  int n;
  cin >> n;
  ll a[n];
  SegTree<ll> st(n,[](ll a,ll b){return max(a,b);},(ll)0);
  set<ll> s;
  rep(i,n) {
    cin >> a[i];
    s.insert(a[i]);
    st.update(i,a[i]);
  }
  map<ll,ll> m;
  ll p = 0;
  for(auto k : s) m[k] = p++;
  SegTree<ll> num(p,[](ll a, ll b){return a + b;},(ll)0);
  SegTree<ll> sum(p,[](ll a, ll b){return a + b;},(ll)0);
  rep(i,n) {
    num.update(m[a[i]],1);
    sum.update(m[a[i]],a[i]);
  }
  vector<ll> ans(n,0);
  rep(i,n) ans[0] += min(a[0],a[i]);
  num.update(m[a[0]],-1);
  sum.update(m[a[0]],-a[0]);
  for(int i = 1; i < n; i++) {
    ll d = st.query(0,i);
    ll c = sum.query(m[d],m[a[i]]);
    ll e = num.query(m[d],m[a[i]]);
    ll f = num.query(m[a[i]],p);
    ans[i] = f*max((ll)0,a[i]-d) + c - e*d;
    num.update(m[a[i]],-1);
    sum.update(m[a[i]],-a[i]);
  }
  for(auto k : ans) cout << k << endl;
  return 0;
}