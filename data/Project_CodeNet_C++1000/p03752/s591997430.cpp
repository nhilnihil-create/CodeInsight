#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N,K;
  cin>>N>>K;
  vector<int64_t>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int64_t ans=1e18;
  for(int s=0;s<(1<<N);s++){
    vector<int>h(N);
    int k=0; 
    for(int i=0;i<N;i++){
      if((s>>i)&1){h[i]=1;k++;}
    }
    if(k<K){continue;}
    int64_t MIN=0;
    int64_t cost=0;
    for(int i=0;i<N;i++){
      if(i==0){MIN=a[0];}
      else if(h[i]==1&&a[i]<=MIN){
        int dis=MIN-a[i];
        cost+=dis+1;
        MIN=a[i]+dis+1;
      }
      else{MIN=max(MIN,a[i]);}
    }
    ans=min(ans,cost);
  }
  cout<<ans<<endl;
  return 0;  
}