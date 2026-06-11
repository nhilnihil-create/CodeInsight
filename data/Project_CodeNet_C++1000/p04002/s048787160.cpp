#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,x,n) for(int i=(x);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define int long long
using namespace std;
const int MOD=1e9+7;
const int INF=1e10;

int mx[9]={-1,0,1,-1,0,1,-1,0,1};
int my[9]={-1,-1,-1,0,0,0,1,1,1};

signed main(){
  int h,w,n;
  cin>>h>>w>>n;
  set<pair<int,int>> s;
  vector<pair<int,int>> p(n);
  rep(i,n){
    int y,x;
    cin>>y>>x;
    y--;x--;
    p[i]={y,x};
    s.insert({y,x});
  }
  vector<int> ans(10,0);
  set<pair<int,int>> used;
  rep(i,n){
    rep(j,9){
      int tmp=0;
      int ny=p[i].first+my[j];
      int nx=p[i].second+mx[j];
      if(1<=nx&&nx<=w-2&&1<=ny&&ny<=h-2&&!used.count({ny,nx})){
        used.insert({ny,nx});
        rep(k,9){
          int nny=ny+my[k];
          int nnx=nx+mx[k];
          if(s.count({nny,nnx}))tmp++;
        }
        ans[tmp]++;
      }

    }
  }
  int sum=accumulate(all(ans),0);

  rep(i,10){
    if(i==0)cout<<(h-2)*(w-2)-sum<<endl;
    else cout<<ans[i]<<endl;
  }
  return 0;
}
