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
  ll N;
  cin>>N;
  vector<ll> A(N);
  rep(i,N) cin>>A[i];

  ll sum=0;
  rep(i,N) sum+=A[i];
  ll M=N*(N+1)/2;
  if(sum%M!=0){
      cout<<"NO"<<endl;
      return 0;
  }

  ll X=sum/M;
  vector<ll> diff(N,0);
  for(int i=0;i<N;i++){
      if(A[i]<X){
          cout<<"NO"<<endl;
          return 0;
      }
      diff[i]=(A[(i+1)%N]-A[i]);
  }
  rep(i,N) diff[i]-=X;

  ll ans=0;
  for(int i=0;i<N;i++){
      if(diff[i]>0||diff[i]%N!=0){
          cout<<"NO"<<endl;
          return 0;
      }
      ans+=abs(diff[i])/N;
  }
  if(ans==X) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

  return 0;
}
