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
  int n,h,w;
  cin>>w>>h>>n;
  int maxx=w,maxy=h,minx=0,miny=0;
  rep(i,0,n){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1){
      minx=max(minx,x);
    }
    else if(a==2){
      maxx=min(maxx,x);
    }
    else if(a==3){
      miny=max(miny,y);
    }
    else if(a==4){
      maxy=min(maxy,y);
    }
  }
  if(maxx-minx<0 || maxy-miny<0)cout<<0<<endl;
  else cout<<(maxx-minx)*(maxy-miny)<<endl;
}