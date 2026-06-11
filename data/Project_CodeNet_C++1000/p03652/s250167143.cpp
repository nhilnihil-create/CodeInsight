#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin >> n >> m;
  vector<vector<int>> a(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<bool> c(m,true);
  int ans=1000;
  for(int k=0;k<m;k++){
    vector<int> v(m);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(c[a[i][j]]){
          v[a[i][j]]++;
          break;
        }
      }
    }
    int cnt=0;
    int t;
    for(int i=0;i<m;i++){
      if(cnt<v[i]){
        cnt=v[i];
        t=i;
      }
    }
    ans=min(ans,cnt);
    c[t]=false;
  }
  cout << ans << endl;
}