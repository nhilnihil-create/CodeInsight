#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

const int Q=3e4;

int main(){
  int N;
  cin>>N;
  vector<int> P(N);
  rep(i,N) cin>>P[i];

  vector<int> A(N,0),B(N,0);
  rep(i,N){
    A[i]=Q;
    if(i>0) A[i]+=A[i-1];
  }
  for(int i=N-1;i>=0;i--){
    B[i]=Q;
    if(i<N-1) B[i]+=B[i+1];
  }

  for(int i=0;i<N;i++){
    A[P[i]-1]+=i;
  }

  rep(i,N) cout<<A[i]<<" ";
  cout<<endl;
  rep(i,N) cout<<B[i]<<" ";
  cout<<endl;

  return 0;
}
