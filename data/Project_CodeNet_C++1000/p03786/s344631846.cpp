#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF=1e18+1;
const int mod = 1000000007;

int main() {
  int N;
  cin>>N;
  vector<int64_t>A(N);
  vector<int64_t>sum(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  sum=A;
  for(int i=0;i<N-1;i++){
    sum[i+1]+=sum[i];
  }
  for(int i=N-2;i>=0;i--){
    if(sum[i]*2<A[i+1]){cout<<N-1-i<<endl;return 0;}
  }
  cout<<N<<endl;
  return 0;
}