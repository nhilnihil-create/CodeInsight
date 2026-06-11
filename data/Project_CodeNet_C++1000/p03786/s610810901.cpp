#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
  ll N,index=0,sum=0;
  cin>>N;
  ll A[N];
  for(ll i=0;i<N;i++) cin>>A[i];
  sort(A,A+N);
  for(ll i=0;i<N-1;i++){
      sum+=A[i];
      if(A[i+1]>sum*2){
          index=i+1;
      }
  }
  cout<<N-index<<endl;
}