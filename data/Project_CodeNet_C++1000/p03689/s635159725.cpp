#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
int mod2=998244353;

signed main(){
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  if(H%h==0&&W%w==0){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;

  if(W%w!=0){
    vector<int> ww(W);
    for(int i=0;i<W;i++){
      if(i%w==w-1)ww[i]=-1e6*(w-1)-1;
      else ww[i]=1e6;
    }
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(j)cout<<" ";
        cout<<ww[j];
      }
      cout<<endl;
    }
  }else{
    vector<int> hh(H);
    for(int i=0;i<H;i++){
      if(i%h==h-1)hh[i]=-1e6*(h-1)-1;
      else hh[i]=1e6;
    }
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        if(j)cout<<" ";
        cout<<hh[i];
      }
      cout<<endl;
    }
  }
}
