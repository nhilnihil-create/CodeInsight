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

int main(){
  int N;
  ll X;
  cin>>N>>X;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  vector<ll> mi(N);
  ll sum=0;
  rep(i,N){
      mi[i]=A[i];
      sum+=A[i];
  }

  ll ans=sum;
  for(int k=1;k<=N;k++){
      ll res=X*k;
      for(int i=0;i<N;i++){
          mi[i]=min(mi[i],A[(i-k+N)%N]);
          res+=mi[i];
      }
      ans=min(ans,res);
  }
  cout<<ans<<endl;


  return 0;
}
