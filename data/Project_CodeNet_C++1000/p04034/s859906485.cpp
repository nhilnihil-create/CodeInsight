#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> cnt(n,1),pos(n,0);//pos is bool
  pos[0]=1;
  rep(i,m){
    int x,y;
    cin>>x>>y;
    x--;y--;
    if(pos[x]==1){
      if(cnt[x]==1){
        pos[x]=0;
        pos[y]=1;
      }else{
        pos[y]=1;
      }
    }
    cnt[x]--;
    cnt[y]++;
  }
  
  int ans=0;
  rep(i,n){
    if(pos[i]==1)ans++;
  }  
  cout<<ans<<endl;
}