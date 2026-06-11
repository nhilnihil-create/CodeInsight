#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int H,W;
  cin>>H>>W;
  vector<string>a(H);
  for(int i=0;i<H;i++){
    cin>>a[i];
  }
  map<char,int>k;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      k[a[i][j]]++;
    }
  }
  int cnt4=0,cnt2=0,cnt1=0;
  for(auto c:k){
    auto key=c.first;
    auto v=c.second;
    int a4=v/4;
    int a2=(v/2*2-a4*4)/2;
    int a1=v-a4*4-a2*2;
    cnt4+=a4,cnt2+=a2,cnt1+=a1;
  }
  if(H%2==0&&W%2==0){
    if(cnt4*4==H*W){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  else if(H%2!=0&&W%2!=0){
    if(cnt1==1&&cnt2<=(H+W-2)/2){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  else{
    if(H%2!=0){
      if(cnt2<=W/2&&cnt1==0){cout<<"Yes"<<endl;}
      else{cout<<"No"<<endl;}
    }
    else{
      if(cnt2<=H/2&&cnt1==0){cout<<"Yes"<<endl;}
      else{cout<<"No"<<endl;}
    }
  }
  return 0;  
}