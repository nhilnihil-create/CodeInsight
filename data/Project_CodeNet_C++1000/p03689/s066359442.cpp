#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll field[505][505]={0};
void judge(ll H,ll W,ll h,ll w){
  ll rsum[505][505]={0};
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      rsum[i][j]=field[i-1][j-1];
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      rsum[i][j]+=rsum[i][j-1];
    }
  }
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      rsum[i][j]+=rsum[i-1][j];
    }
  }
  for(int i=h;i<=H;i++){
    for(int j=w;j<=W;j++){
      ll ksum=rsum[i][j]+rsum[i-h][j-w];
      ksum-=rsum[i-h][j];
      ksum-=rsum[i][j-w];
      if(ksum>=0){
        cout<<"No"/*<<i<<" "<<j*/<<endl;
        return;
      }
    }
  }
  if(rsum[H][W]<=0){
    cout<<"No"<<endl;
    return;
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cout<<field[i][j]<<" ";
    cout<<endl;
  }
  return;
}
int main(){
  ll H,W,h,w;
  cin>>H>>W>>h>>w;
/*  if(H%h==0&&W%w==0){
    cout<<"No"<<endl;
    return 0;
  } */
  ll hk=H/h,wk=W/w;
  ll val=1e8*5;
  for(int i=0;i<H;i+=h){
    for(int j=0;j<W;j+=w) field[i][j]=val;
  }
  for(int i=h-1;i<H;i+=h){
    for(int j=w-1;j<W;j+=w) field[i][j]=-1*(val+1);
  }
//  cout<<"Yes"<<endl;
/*  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cout<<field[i][j]<<" ";
    cout<<endl;
  } */
  judge(H,W,h,w);
}
