
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define INF 1000000000000
#define MOD 1000000007
#define PI 3.14159265359
#define dij priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>
typedef long long ll;
//
int main(){
  int w,h,n;cin>>w>>h>>n;
  vector<vector<int>> v(n,vector<int>(3));
  rep(i,n){
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  int lx=0,rx=w,uy=h,dy=0;
  rep(i,n){
    switch(v[i][2]){
      case 1:
      lx=max(lx,v[i][0]);
      break;
      case 2:
      rx=min(rx,v[i][0]);
      break;
      case 3:
      dy=max(dy,v[i][1]);
      break;
      case 4:
      uy=min(uy,v[i][1]);
      break;
    }
  }
  int a=rx-lx,b=uy-dy;
  int ans;
  if(a>0&&b>0)ans=a*b;
  else ans=0;
  cout<<ans<<endl;
}