#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

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
  vector<vector<char>>a(H+2,vector<char>(W+2));
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<=H+1;i++){
    for(int j=0;j<=W+1;j++){
      if(i==0||j==0||i==H+1||j==W+1){
        a[i][j]='#';
      }
    }
  }
  for(int i=0;i<=H+1;i++){
    for(int j=0;j<=W+1;j++){
      cout<<a[i][j];
    }cout<<endl;
  }
  return 0;  
}