#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

#define pll pair<ll,ll>
ll h,w,n;
map<pll,int> mp;
ll ans[10];

void p(int x,int y){
  FOR(i,y-2,y+1){
    FOR(j,x-2,x+1){
      if(1<=i&&i<=w-2&&1<=j&&j<=h-2)
        mp[pll(i,j)]++;
    }
  }
}

int main(){
  cin>>h>>w>>n;

  rep(i,n){
    int x,y;
    cin>>x>>y;
    p(x,y);
  }

  for(auto itr=mp.begin();itr!=mp.end();itr++){
    ans[itr->second]++;
  }
  ans[0]=(h-2)*(w-2)-mp.size();

  rep(i,10){
    cout<<ans[i]<<endl;
  }

  return 0;
}
