#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>pppp(int64_t x){
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
 
 bool re(vector<int>x,vector<int>y){
   bool ok=true;
   for(int i=0;i<x.size();i++){
     if(x[i]!=y[i]){ok=false;}
   }
   return ok;
  }

int main() {
  string s;
  cin>>s;
  int cnt=0;
  for(int i=0;i<s.size()-1;i++){
   if(s[i+1]!=s[i]){cnt++;}
  }
  cout<<cnt<<endl;
  return 0;
}