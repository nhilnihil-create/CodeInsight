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
  vector<int>a(M),b(M);
  vector<bool>P(N,false),Q(N,false);
  for(int i=0;i<M;i++){
    cin>>a[i]>>b[i];
    if(b[i]==N){P[a[i]]=true;}
    if(a[i]==1){Q[b[i]]=true;}
  }
  for(int i=0;i<N;i++){
    if(Q[i]&&P[i]){cout<<"POSSIBLE"<<endl;return 0;}
  }
  cout<<"IMPOSSIBLE"<<endl;
 return 0;
}