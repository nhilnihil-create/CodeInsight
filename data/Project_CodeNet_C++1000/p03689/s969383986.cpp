#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long H,W,h,w;cin>>H>>W>>h>>w;
  vector<vector<long long>>V(H,vector<long long>(W,1000));
  if(H%h==0&&W%w==0)cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    for(int X=h-1;X<H;X+=h){
      for(int Y=w-1;Y<W;Y+=w){
        V[X][Y]=(h*w-h*w*2+1)*1000-1;
      }
    }
    for(int X=0;X<H;X++){
      for(int Y=0;Y<W;Y++){
        if(Y==W-1)cout<<V[X][Y]<<endl;
        else cout<<V[X][Y]<<" ";
      }
    }
  }
}
