#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
const int mod = 1000000007;
using pint=pair<ll,ll>;
 
// union by size + path having
class UnionFind {
public:
   vector <ll> par; // 各元の親を表す配列
   vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)
 
   // Constructor
   UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
       for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
   }
   void init(ll sz_) {
       par.resize(sz_);
       siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
       for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
  }
 
   // Member Function
   // Find
   ll root(ll x) { // 根の検索
      while (par[x] != x) {
           x = par[x] = par[par[x]]; // x の親の親を x の親とする
       }
       return x;
  }
 
   // Union(Unite, Merge)
   bool unite(ll x, ll y) {
       x = root(x);
       y = root(y);
       if (x == y) return false;
       // merge technique（データ構造をマージするテク．小を大にくっつける)
       if (siz[x] < siz[y]) swap(x, y);
       siz[x] += siz[y];
       par[y] = x;
       return true;
  }
 
  bool same(ll x, ll y) { // 連結判定
       return root(x) == root(y);
  }
 
  ll size(ll x) { // 素集合のサイズ
      return siz[root(x)];
  }
};
 
ll modpow(ll x, ll n) {
   x = x%mod;
   if(n==0) return 1;  //再帰の終了条件
 
   else if(n%2==1) {
       return (x*modpow(x, n-1))%mod;  //nが奇数ならnを1ずらす
   }
   else return modpow((x*x)%mod, n/2)%mod;  //nが偶数ならnが半分になる
}
 
ll com(ll n, ll k) {
   ll x = 1;
   for(int i=n-k+1; i<=n; i++) {
      x = x*i%mod;
   }
 
   ll y = 1;
   for(int i=1; i<=k; i++) {
       y = y*i%mod;
   }
   y = modpow(y, mod-2);
 
   return x*y%mod;
}
 
int main(){

    ll n,a,b,cntb=0,tsuuka=0;
    string s;
    cin >> n >> a >> b >> s;
    rep(i,n){
        if(s[i]=='c') cout << "No" << endl;
        else if(s[i]=='a'){
            if(tsuuka<a+b){
                cout << "Yes" << endl;
                tsuuka++;
            }
            else cout << "No" << endl;
        }
        else if(s[i]=='b'){
            cntb++;
            if(tsuuka<a+b && cntb<=b){
                cout << "Yes" << endl;
                tsuuka++;
            }
            else cout << "No" << endl;
        }
    }
 
}