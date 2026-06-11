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
  cin>>N;
  vector<int> A(N);
  rep(i,N) cin>>A[i];

  vector<int> P(N+1,0);
  for(int i=0;i<N;i++){
      P[A[i]]=i;
  }

  ll ans=0;
  set<int> se;
  se.insert(-1);
  se.insert(N);
  for(int i=1;i<=N;i++){
      ll now=P[i];
      auto itr=se.upper_bound(now);
      ll r=*itr;
      itr--;
      ll l=*itr;
      se.insert(now);

      l++;
      r--;
      ans+=(now-l+1)*(r-now+1)*i;
  }
  cout<<ans<<endl;

  return 0;
}
