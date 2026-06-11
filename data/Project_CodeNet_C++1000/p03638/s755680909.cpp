#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int h,w;
  cin >> h >> w;
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  int ans[h][w];
  int i,j;
  int h_1=0,w_1=0;
  for(i=0;i<n;i++){
    for(j=1;j<=a.at(i);j++){
      ans[h_1][w_1]=i+1;
      w_1++;
      if(w_1==w){
        w_1=0;
        h_1++;
      }
    }
  }
  for(i=0;i<h;i++){
    if(i%2==1){
      for(j=0;j<w/2;j++){
        int cp=ans[i][j];
        ans[i][j]=ans[i][w-1-j];
        ans[i][w-1-j]=cp;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}
      
               