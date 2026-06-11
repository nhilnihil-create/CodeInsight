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
 
 int64_t func (int x){
   int64_t sum=1;
   for(int i=1;i<=x;i++){
     sum*=i;
     sum%=1000000007;
   }
   return sum;
 }
int main() {
  int64_t N,M;
  cin>>N>>M;
  if(abs(N-M)>=2){cout<<0<<endl;}
  else{
    if(abs(N-M)==1){cout<<func(N)*func(M)%1000000007<<endl;}
    else if(N==M){cout<<func(N)*func(M)*2%1000000007<<endl;}
    }
  return 0;
}