#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
template< typename T >
struct BIT {
  int N; int max_2beki;

  vector< T > data;
  // 初期化 1-indexedでデータを管理する 0で初期化
  BIT(int size){
      N = ++size;
      data.assign(N, 0);
      max_2beki = 1;
      while(max_2beki * 2 <= N) max_2beki *= 2;
  }

  // [0,k](閉区間)の総和 閉区間に注意！
  T sum(int k) {
    if(k < 0) return 0; // k<0のとき0を返す
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  // [l,r](閉区間)の総和
  inline T sum(int l,int r){
    return sum(r) - sum(l-1);
  }

  // 一点取得 更新はできないことに注意
  inline T operator[](int k){
    return sum(k) - sum(k-1);
  }

  // data[k] += x;
  void add(int k, T x) {
    for(++k; k < N; k += k & -k) data[k] += x;
  }

  // imos法 [l,r]にxを加算
  void imos(int l,int r,T x){
    add(l , x); add(r + 1 , -x);
  }

  // lower_bound sum(i)がval以上となる最小のi
  int lower_bound(T w){
    if(w <= 0) return 0;
    int x = 0;
    for(int k = max_2beki; k > 0; k /= 2){
      if(x+k <= N - 1 && data[x + k] < w){
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // upper_bound sum(i)がvalより大きくなる最小のi
  int upper_bound(T w){
    if(w < 0) return 0;
    int x = 0;
    for(int k = max_2beki; k > 0; k /= 2){
      if(x+k <= N - 1 && data[x + k] <= w){
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin >> n >> k;
    vector<pair<ll,ll>> p(n+1);
    vector<ll> sum(n+1);
    rep(i,n){
        ll a;cin >> a;
        sum[i+1]=sum[i]+a;
    }
    BIT<int> bit(n+1);
    rep(i,n+1){
        p[i]={sum[i]-k*i,i};
    }
    sort(p.begin(),p.end());
    ll ans=0;
    rep(i,n+1){
        ans+=bit.sum(p[i].second);
        bit.add(p[i].second,1);
    }
    cout << ans << endl;
}