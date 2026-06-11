#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  ll H,W;cin>>H>>W;
  if(H%3==0 || W%3==0) cout<<0<<endl;
  else{
    ll tmp=1e18;
    rep(i,W){
      ll block1,block2,block3;
      block1=i*H;
      block2=(W-i)*((H+1)/2);
      block3=(W-i)*(H/2);
      tmp = min(tmp,max(block1,max(block2,block3))-min(block1,min(block2,block3)));
    }
    rep(i,W){
      ll block1,block2,block3;
      block1=i*H;
      block2=((W-i+1)/2)*H;
      block3=((W-i)/2)*H;
      tmp = min(tmp,max(block1,max(block2,block3))-min(block1,min(block2,block3)));
    }
    rep(j,H){
      ll block1,block2,block3;
      block1=j*W;
      block2=(H-j)*((W+1)/2);
      block3=(H-j)*(W/2);
      tmp = min(tmp,max(block1,max(block2,block3))-min(block1,min(block2,block3)));
    }
    rep(j,W){
      ll block1,block2,block3;
      block1=j*W;
      block2=((H-j+1)/2)*W;
      block3=((H-j)/2)*W;
      tmp = min(tmp,max(block1,max(block2,block3))-min(block1,min(block2,block3)));
    }
    cout << tmp << endl;
  }
}