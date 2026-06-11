#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  int a[n][m];
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin>>a[i][j];
  }
  int ans=100000;
  bool used[m+1];
  fill(used,used+m+1,false);
  int cnt[n];
  fill(cnt,cnt+n,0);
  for(int k=0;k<m;k++){
    int cn[m+1];
    fill(cn,cn+m+1,0);
    for(int i=0;i<n;i++){
      if(cnt[i]==m)continue;
      cn[a[i][cnt[i]]]++;
    }
    int ma=0,num;
    for(int i=1;i<=m;i++){
      if(cn[i]>ma){
        ma=cn[i];
        num=i;
      }
    }
    ans=min(ans,ma);
    used[num]=true;
    for(int i=0;i<n;i++){
      while(cnt[i]<m&&used[a[i][cnt[i]]])cnt[i]++;
    }
  }
  cout<<ans<<endl;
}
    
        
      
    