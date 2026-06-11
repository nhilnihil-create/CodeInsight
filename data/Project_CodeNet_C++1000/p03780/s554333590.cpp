#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
 
int main(){
  int N, K;cin>>N>>K;
  vi a;
  a.push_back(0);
  for (int i=0;i<N;++i){
    int a_;cin>>a_;a.push_back(a_);
  }
  a.push_back(0);
 
  int left[2][K+1], right[2][K+1];
  memset(left, -1, sizeof(left));
  memset(right, -1, sizeof(right));
 
  left[0][0]=1;
  right[0][0]=1;
  vi l_sum[N+2], r_sum[N+2];
  l_sum[0].push_back(0);r_sum[N+1].push_back(0);
 
  for (int i=0;i<N+1;++i){
    for (int j=0;j<K+1;++j){
      if(left[0][j]==1||(j>=a[i+1]&&left[0][j-a[i+1]]==1)) {
        left[1][j]=1;
        l_sum[i+1].push_back(j);
      }
    }
    for (int j=0;j<K+1;++j) {left[0][j]=left[1][j];}
  }
 
  for (int i=N+1;i>=1;--i){
    for (int j=0;j<K+1;++j){
      if(right[0][j]==1||(j>=a[i-1]&&right[0][j-a[i-1]]==1)) {
        right[1][j]=1;
        r_sum[i-1].push_back(j);
      }
    }
    for (int j=0;j<K+1;++j) {right[0][j]=right[1][j];}
  }
 
  
  int ans=0;
  
 
  for (int i=1;i<N+1;++i){
    int L=l_sum[i-1].size();
    int patience=1;
    for (int l=0;l<L;++l){
      int R=r_sum[i+1].size();
      int x=lower_bound(r_sum[i+1].begin(), r_sum[i+1].end(), K-l_sum[i-1][l]-a[i])-r_sum[i+1].begin();
      if (x>R-1) continue;
      if(r_sum[i+1][x]+l_sum[i-1][l]<K) patience=0;
    }
    if(patience==1) ans++;
  }
 
  cout << ans << endl;
  return 0;
}