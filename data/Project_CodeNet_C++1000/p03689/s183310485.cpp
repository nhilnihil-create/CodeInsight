#include <bits/stdc++.h>
using namespace std;
const int INF=1e5;

signed main(){
  int H,W,h,w;cin>>H>>W>>h>>w;
  if(W%w){
    cout<<"Yes"<<endl;
    vector<int> v(W+1,0);
    for(int i=1;i<w;i++)v[i]=INF;
    for(int i=w;i<=W;i++)v[i]=v[i-w]-1;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++)cout<<v[j+1]-v[j]<<" ";cout<<endl;
    }
    return 0;
  }
  if(H%h){
    cout<<"Yes"<<endl;
    vector<int> v(H+1,0);
    for(int i=1;i<h;i++)v[i]=INF;
    for(int i=h;i<=H;i++)v[i]=v[i-h]-1;
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++)cout<<v[i+1]-v[i]<<" ";cout<<endl;
    }
    return 0;
  }
  cout<<"No"<<endl;
}
