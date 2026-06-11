#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

template<typename T>
struct BinaryIndexedTree {
  int N;
  vector<T> data;
 
  BinaryIndexedTree(int sz) : N(sz), data(sz+1,0) {}
 
  T sum(int k) { // [0,k) (0-indexed) a[0] + … + a[k-1]
    T ret = 0;
    for(; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
 
  T sum(int l, int r) { // [l,r) (0-indexed) a[l] + …　+ a[r-1]
    T vl = sum(l);
    T vr = sum(r);
    return vr - vl;
  }
 
  void add(int k, T x) { // (0-indexed) a[k] += x;
    for(++k; k <= N; k += k & -k) data[k] += x;
  }
 
  int lowerbound(T x) { // (0-indexed)
    int k = 1;
    int ret = 0;
    while ((k<<1) <= N) k <<= 1;
    while (k > 0) {
      if (ret + k <= N && data[ret+k] < x) {
        x -= data[ret+k];
        ret += k;
      }
      k >>= 1;
    }
    return ret;
  }
 
  int upperbound(T x) { // (0-indexed)
    ++x;
    int k = 1;
    int ret = 0;
    while ((k<<1) <= N) k <<= 1;
    while (k > 0) {
      if (ret + k <= N && data[ret+k] < x) {
        x -= data[ret+k];
        ret += k;
      }
      k >>= 1;
    }
    return ret;
  }
};

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}
/*
  vector<int> as, comp(n);
  as = compress(a);
  int sz=as.size();
  rep(i,n){ comp[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin(); }
*/  

int main(){
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n,0);
  rep(i,n) cin >> a[i];
  vector<ll> r(n+1,0);
  rep(i,n){
    r[i+1] = r[i] + a[i] - k;
  }
  vector<ll> z = compress(r);
  vector<int> comp(n+1);
  rep(i,n+1){ comp[i] = lower_bound(z.begin(), z.end(), r[i]) - z.begin(); }

  BinaryIndexedTree<int> bt(n+2);
  ll ans = 0;
  rep(i,n+1){
    ans += bt.sum(0,comp[i]+1);
    bt.add(comp[i],1);
  }
  cout << ans << endl;
  return 0;
}