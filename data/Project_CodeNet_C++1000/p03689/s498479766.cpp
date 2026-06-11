#include <bits/stdc++.h>
using namespace std;
int main(){
  long long H,W,h,w,sum=0;
  cin >> H >> W >> h >> w;
  int ans[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      ans[i][j]=1000;
      sum+=1000;
    }
  }
  for(int i=h-1;i<H;i+=h){
    for(int j=w-1;j<W;j+=w){
      ans[i][j]=-(h*w-1)*1000-1;
      sum-=1000;
      sum+=ans[i][j];
    }
  }
  if(sum<=0){
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout << ans[i][j] << ((j==W-1)?'\n':' ');
    }
  }
  return 0;
}