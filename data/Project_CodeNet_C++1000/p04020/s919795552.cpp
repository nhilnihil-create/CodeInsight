#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  int64_t sum=0;
  for(int i=0;i<N;i++){
    if(i<N&&A[i+1]!=0){
      if(A[i]%2!=0){
        sum++;A[i]--;A[i+1]--;
      }
    }
    sum+=A[i]/2;
  }
  cout<<sum<<endl;
  return 0;
}