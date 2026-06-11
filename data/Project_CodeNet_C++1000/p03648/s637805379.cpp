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

ll K;
const int N=50;

int main(){
  cin>>K;

  vector<ll> A(N,0);
  for(int i=0;i<N;i++) A[i]=N-1+(K/N);

  K%=N;
  for(int i=0;i<K;i++){
      A[i]=A[i]+N-(K-1);
  }
  for(int i=K;i<N;i++){
      A[i]=A[i]-K;
  }

  cout<<N<<endl;
  for(int i=0;i<N;i++) cout<<A[i]<<" ";
  cout<<endl;

  return 0;
}
