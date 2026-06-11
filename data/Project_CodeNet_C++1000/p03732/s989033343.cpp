#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  ll W;
  cin>>n>>W;
  ll w[n];
  int v[n];
  vector<int> a[4];
  rep(i,0,n){
    cin>>w[i]>>v[i];
  }
  rep(i,0,n){
    a[w[i]-w[0]].push_back(v[i]);
  }
  rep(i,0,4){
    sort(a[i].rbegin(),a[i].rend());
  }
  vector<int> b[4];
  rep(i,0,4){
    b[i].push_back(0);
    rep(j,0,a[i].size()){
      b[i].push_back(b[i][b[i].size()-1]+a[i][j]);
    }
  }
  int ans=0;
  rep(i,0,b[0].size()){
    rep(j,0,b[1].size()){
      rep(k,0,b[2].size()){
        rep(l,0,b[3].size()){
          if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+l*(w[0]+3)<=W){
            ans=max(ans,b[0][i]+b[1][j]+b[2][k]+b[3][l]);
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}