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
  int N,K;
  cin>>N>>K;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  vector<ll> sum(N+1,0);
  vector<ll> masum(N+1,0);
  for(int i=0;i<N;i++){
    masum[i+1]=masum[i]+max(0ll,A[i]);
    sum[i+1]=sum[i]+A[i];
  }

  ll ans=0;
  for(int i=K;i<=N;i++){
    ans=max(ans,masum[N]-masum[i]+masum[i-K]+max(0ll,sum[i]-sum[i-K]));
  }
  cout<<ans<<endl;

  return 0;
}
