#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
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
 
int main() {
 int N,M;
 cin>>N>>M;
 int x[1000000];
 int y[1000000];
 for(int i=0;i<M;i++){
   cin>>x[i]>>y[i];
   x[i]--;y[i]--;
 }
 vector<int>s(N,1);
 vector<bool>aka(N,false);
 aka[0]=true;
 for(int i=0;i<M;i++){
  s[y[i]]++;s[x[i]]--;
  if(aka[x[i]]){aka[y[i]]=true;}
  if(s[x[i]]==0){aka[x[i]]=false;}
 }
 int cnt=0;
 for(int i=0;i<N;i++){
   if(aka[i]){cnt++;}
 }
 cout<<cnt<<endl;
 return 0;
}