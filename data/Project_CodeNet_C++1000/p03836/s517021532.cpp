#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int sx,sy,tx,ty;
  cin>>sx>>sy>>tx>>ty;
  string ans="";
  rep(i,0,tx-sx) ans+='R';
  rep(i,0,ty-sy) ans+='U';
  rep(i,0,tx-sx) ans+='L';
  rep(i,0,ty-sy+1) ans+='D';
  rep(i,0,tx-sx+1) ans+='R';
  rep(i,0,ty-sy+1) ans+='U';
  ans+='L';
  ans+='U';
  rep(i,0,tx-sx+1) ans+='L';
  rep(i,0,ty-sy+1) ans+='D';
  ans+='R';
  cout<<ans<<endl;
}







