#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////



int n,l,q,x[110000];P qr[110000];
int d[22][110000];
signed main(){
  cin>>n;rep(i,n)cin>>x[i];
  cin>>l>>q;
  rep(i,q)cin>>qr[i].first>>qr[i].second;
  rep(i,22)rep(j,110000)d[i][j] = INF;
  rep(i,n){
    auto itr = upper_bound(x+i, x+n, x[i]+l)-1;
    d[0][i] = itr - x;
    if(i == n-1)d[0][i] = INF;
  }
  rep(k,21){
    rep(i,n){
      if(d[k][i] == INF)continue;
      d[k+1][i] = d[k][d[k][i]];
    }
  }

  rep(i,q){
    int a = qr[i].first, b = qr[i].second;a--;b--;
    if(a > b)swap(a, b);
    int ans = 0, now = a;
    while(now < b){
      int ok = 0, ng = 22;
      while(abs(ok - ng) > 1){
        int mid = (ok+ng)/2;
        if(d[mid][now] <= b)ok = mid;
        else ng = mid;
      }
      now = d[ok][now];
      int plus = 1;
      rep(i,ok)plus *= 2;
      ans += plus;
    }
    cout << ans << endl;
  }
}

