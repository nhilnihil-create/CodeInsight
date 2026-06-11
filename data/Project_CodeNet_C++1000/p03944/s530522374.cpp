#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>func(int64_t x){
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

int main(){
  int w,h,n;
  cin>>w>>h>>n;
  vector<int>x(n);
  vector<int>y(n);
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i]>>a[i];
  }
  int l=0,r=w,u=h,d=0;
  for(int i=0;i<n;i++){
    if(a[i]==1){l=max(l,x[i]);}
    if(a[i]==2){r=min(r,x[i]);}
    if(a[i]==3){d=max(d,y[i]);}
    if(a[i]==4){u=min(u,y[i]);}
  }
  if(r-l<0||u-d<0){cout<<0<<endl;}
  else{cout<<(r-l)*(u-d)<<endl;}
  return 0;
}