#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int W,H,N;
  cin>>W>>H>>N;
  int XH=W,YH=H,XL=0,YL=0;
  rep(i,N){
    int X,Y,A;
    cin>>X>>Y>>A;
    if(A==1){
      if(XL<=X)XL=X;
    }
    if(A==2){
      if(XH>=X)XH=X;
    }
    if(A==3){
      if(YL<=Y)YL=Y;
    }
    if(A==4){
      if(YH>=Y)YH=Y;
    }
  }
  int ans=(XH-XL)*(YH-YL);
  if(XH-XL<0&&YH-YL<0)ans=0;
  if(ans<0)ans=0;
  cout<<ans<<endl;
  return 0;
}
