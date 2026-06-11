#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
 int N;
 cin>>N;
 vector<int>A(N);
 vector<int>B(N);
 for(int i=0;i<N;i++){
     cin>>A[i]>>B[i];
 }
 int64_t ans=0;
 for(int i=N-1;i>=0;i--){
  if((A[i]+ans)%B[i]==0){continue;}
  ans+=B[i]-(A[i]+ans)%B[i];
 }
 cout<<ans<<endl;
 return 0;
}