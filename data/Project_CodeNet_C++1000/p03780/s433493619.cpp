#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
//#define int long long
#define double long double

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////

int n,k,a[5100],x[5100][5100],y[5100][5100];
signed main(){
  cin>>n>>k;rep(i,n)cin>>a[i+1];
  x[0][0] = y[n+1][0] = 1;
  repd(i,1,n+1){
    rep(j,k+1){
      x[i][j] = (x[i-1][j] || (j-a[i] >= 0 && x[i-1][j-a[i]]));
    }
  }
  for(int i = n;i >= 1;i--){
    rep(j,k+1){
      y[i][j] = (y[i+1][j] || (j-a[i] >= 0 && y[i+1][j-a[i]]));
    }
  }
  int ans = 0;

  rep(i,n+2){
    repd(j,1,k+2)y[i][j] += y[i][j-1];
  }
 // rep(i,n+2)rep(j,k+2)cout << x[i][j] << (j == k+1 ? "\n" : " ");
 // cout << endl;
 // rep(i,n+2)rep(j,k+2)cout << y[i][j] << (j == k+1 ? "\n" : " ");
  repd(i,1,n+1){
    rep(j,k){
      if(!x[i-1][j])continue;
      int l = k-a[i]-j-1, u = k-j-1;
      if(y[i+1][u]-(l < 0 ? 0 : y[i+1][l])){
        ans++;break;
      }
    }
  }
  cout << n-ans << endl;
}


