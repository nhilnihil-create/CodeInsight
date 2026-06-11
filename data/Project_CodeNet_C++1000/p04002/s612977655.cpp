#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;
typedef pair<int,int>P;
map<P,int>p;
int dx[]={0,1,1,1,0,-1,-1,-1,0};
int dy[]={-1,-1,0,1,1,1,0,-1,0};
ll ans[19];

int main(){
  ll h,w,n;
  cin>>h>>w>>n;
  rep(i,n){
    int x,y;
    cin>>y>>x;
    y--;x--;
    rep(j,9){
      int nx=x+dx[j];
      int ny=y+dy[j];
      if(0<nx&&nx<w-1&&0<ny&&ny<h-1){
        p[P(nx,ny)]++;
      }
    }
  }

  ans[0]=(h-2)*(w-2);
  for(auto pi:p){
    ans[pi.se]++;
  }
  for(int i=1;i<=9;i++){
    ans[0]-=ans[i];
  }
  rep(i,10){
    cout<<ans[i]<<endl;
  }
  return(0);
}

