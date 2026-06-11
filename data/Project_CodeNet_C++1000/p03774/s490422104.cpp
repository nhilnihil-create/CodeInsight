#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const ll inf=1e9;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n,m;
  cin >> n >> m;
  vector<int>a(n),b(n),c(m),d(m);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,m) cin >> c[i] >> d[i];
  vector<int> ans(n);
  rep(i,n){
    int dist = inf;
    int pos = m;
    rep(j,m){
      int di = abs(a[i]-c[m-1-j])+abs(b[i]-d[m-1-j]);
      if(di<=dist){
        dist = di;
        pos = m-1-j+1;
      }
    }
    ans[i]=pos;
  }
  rep(i,n) cout << ans[i] << endl;
  return 0;
}
