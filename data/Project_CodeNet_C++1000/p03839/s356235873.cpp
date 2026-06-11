#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

template <class T>
struct SegmentTree{
  using F = function<T(T,T)>;
  F f;
  T inf;
  int n;
  vector<T> node;

  SegmentTree(vector<T> v,T inf,F f):inf(inf),f(f){
    n = 1; while(n < v.size()) n *= 2;
    node.resize(2*n-1,inf);
    for(int i = 0; i < v.size(); i++) node[i+n-1] = v[i];
    for(int i = n-2; i >= 0; i--) node[i] = f(node[2*i+1],node[2*i+2]);
  }

  void update(int k,T val){
    k += n-1;
    node[k] = val;
    while(k > 0){
      k = (k-1) / 2;
      node[k] = f(node[2*k+1],node[2*k+2]);
    }
  }

  void add(int k,T val){
    k += n-1;
    node[k] += val;
    while(k > 0){
      k = (k-1) / 2;
      node[k] = f(node[2*k+1],node[2*k+2]);
    }
  }

  T getval(int a,int b){ return getval(a,b,0,0,n); }
  T getval(int a,int b,int k,int l,int r){
    //区間[a, b)の値を返す
    if(r <= a || b <= l) return inf;
    if(a <= l && r <= b) return node[k];
    T vl = getval(a, b, 2*k+1, l, (l+r)/2);
    T vr = getval(a, b, 2*k+2, (l+r)/2, r);
    return f(vl, vr);
  }
};

signed main(){

  int n,k; cin >> n >> k;
  vector<int> a(n),v(n,0);
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] < 0) v[i] = a[i];
    sum += a[i];
  }

  SegmentTree<int> seg1(a,0,[&](int x,int y){
    return (x + y);
  });
  SegmentTree<int> seg2(v,0,[&](int x,int y){
    return (x + y);
  });

  int ans = 0;
  for(int i = 0; i+k-1 < n; i++){
    int res1 = sum - seg1.getval(i,i+k) - (seg2.getval(0,i) + seg2.getval(i+k,n));
    int res2 = sum - (seg2.getval(0,i) + seg2.getval(i+k,n));
    ans = max({ans,res1,res2});
  }
  cout << ans << endl;

  return 0;
}
