#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

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
  if(H%2==0&&W%2==0){
    for(auto c:k){
      if(c.second%4!=0){cout<<"No"<<endl;return 0;}
    }
    cout<<"Yes"<<endl;
  }
  else if(H%2!=0&&W%2!=0){
    int cnt2=0,cnt1=0;
    for(auto c:k){
      if(c.second%4!=0&&c.second%2==0){cnt2++;}
      if(c.second%4!=0&&c.second%2!=0){cnt1++;}
    }
    if(cnt2<=(H+W-1-1)/2&&cnt1==1){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  else{
    int even;
    if(H%2==0){even=H;}
    else{even=W;}
    int cnt2=0,cnt1=0;
    for(auto c:k){
      if(c.second%2!=0){cout<<"No"<<endl;return 0;}
      if(c.second%4!=0&&c.second%2==0){cnt2++;}
    }
    if(cnt2<=even/2){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  return 0;
}