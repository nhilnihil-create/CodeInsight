#include <bits/stdc++.h>
using namespace std;
#include <math.h>
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


int main() {
  int x,y;
  cin>>x>>y;
  vector<int>a={1,3,5,7,8,10,12},
  b={4,6,9,11},c={2};
  int X=0,Y=0;
  for(int i=0;i<7;i++){
    if(x==a[i]){X=1;}
    if(y==a[i]){Y=1;}
  }
  for(int i=0;i<4;i++){
    if(x==b[i]){X=2;}
    if(y==b[i]){Y=2;}
  }
    if(x==2){X=3;}
    if(y==2){Y=3;}
  
  if(X==Y){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
  return 0;
}