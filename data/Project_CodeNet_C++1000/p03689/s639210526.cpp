#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W,h,w;
  cin>>H>>W>>h>>w;
  if(H%h==0&&W%w==0)cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    if(H%h!=0){
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(i%h==h-1)cout<<-1-1000*(h-1);
          else cout<<1000;
          if(j!=W-1)cout<<' ';
          else cout<<endl;
        }
      }
    }
    else{
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(j%w==w-1)cout<<-1-1000*(w-1);
          else cout<<1000;
          if(j!=W-1)cout<<' ';
          else cout<<endl;
        }
      }
    }
  }
}