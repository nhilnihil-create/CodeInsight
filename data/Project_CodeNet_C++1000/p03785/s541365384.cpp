#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
  int64_t N,C,K;
  cin>>N>>C>>K;
  vector<int64_t>T(N);
  for(int i=0;i<N;i++){
    cin>>T[i];
  }
  sort(T.begin(),T.end());
  int cnt=0;
  for(int i=0;i<N;i++){
    int64_t BT=T[i]+K;
    int64_t cap=C-1;
    cnt++;//cout<<BT<<" "<<cap<<endl;
    while(i+1<N&&cap-1>=0&&T[i+1]<=BT){
      //cout<<i+1<<" "<<cap-1<<endl;;
      i++;
      cap--;
    }
  }
  cout<<cnt<<endl;
  return 0;
}