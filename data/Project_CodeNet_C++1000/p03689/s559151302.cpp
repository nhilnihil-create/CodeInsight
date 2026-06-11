#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int H,W,h,w;
  cin>>H>>W>>h>>w;

  if(H%h==0&&W%w==0){
      cout<<"No"<<endl;
      return 0;
  }

  cout<<"Yes"<<endl;
  ll INF=1e9;
  ll plus=INF/(h*w-1)-1;
  ll ans[H+1][W+1]={};
  for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
          if(i%h==0&&j%w==0) ans[i][j]=-INF;
          else ans[i][j]=plus;
      }
  }

  for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
          cout<<ans[i][j]<<" ";
      }
      cout<<endl;
  }

  return 0;
}
