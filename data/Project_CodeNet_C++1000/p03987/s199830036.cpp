#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <deque>
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(vecll v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }
 
  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
//SegmentTree(n,f,M1) nで初期化　fは二項演算　M1は単位元
//set(k,x) 要素k = x
//build() 構築
//query 区間[a,b)に二項演算
//update(k,x) kをxに
//operator[k] k番目の要素
// SegmentTree< int > seg(N,[](int a,int b){return min(a,b);},INF);
//みたいに使う

main(){
    ll n=in();
    ll ans=0;
    vecll a;
    rep(i,n)a.pb(in());
    SegmentTree< ll > seg(n+1,[](ll a,ll b){return min(a,b);},LLINF);
    rep(i,n){
        seg.set(i,a[i]);
    }
    seg.build();
    rep(i,n){
        ll left,right;
        int l=-1,r=i;
        while(l<r-1){
            int mid=(l+r)/2;
            if(seg.query(mid,i+1)<a[i])l=mid;
            else r=mid;
        }
        left=r;
        l=i,r=n;
        while(l<r-1){
            int mid=(l+r)/2;
            if(seg.query(i+1,mid+1)<=a[i])r=mid;
            else l=mid;
        }
        right=l;
        ans+=a[i]*(i-left+1)*(right+1-i);
        // cout<<ans<<endl;
    }
    cout<<ans;
}