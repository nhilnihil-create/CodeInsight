#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
// int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int w,h,n;
  cin >> w >> h >> n;
  int lx=0,rx=w,uy=h,dy=0;
  rep(i,n){
    int x,y,a;
    cin >> x >> y >> a;
    if(a==1){
      lx=max(x,lx);
    }
    if(a==2){
      rx=min(x,rx);
    }
    if(a==3){
      dy=max(y,dy);
    }
    if(a==4){
      uy=min(y,uy);
    }
    
  }
  
  int s = max(rx-lx,0)*max(uy-dy,0);
  cout << s << endl;
  return 0;
}
