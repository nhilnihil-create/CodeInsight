#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w,n; cin>>h>>w>>n;
  bool flag = true;
  int noww=0,nowh=0;
  vector<vector<int>> ans(h,vector<int>(w));
  for(int i=1;i<=n;i++){
    int a; cin>>a;
    while(a!=0){
      if(flag){
        ans[nowh][noww]=i;
        noww++;
        if(noww==w){
          noww--; nowh++;
          flag=false;
        }
      }else{
        ans[nowh][noww]=i;
        noww--;
        if(noww==-1){
          noww++; nowh++;
          flag=true;
        }
      }a--;
    }
  }for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(j!=w-1){
        cout<<ans[i][j]<<' ';
      }else{
        cout<<ans[i][j]<<endl;
      }
    }
  }
}