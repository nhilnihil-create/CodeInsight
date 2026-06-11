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

int N,M;
vector<int> A;

ll imos[200020];

int main(){
  cin>>N>>M;
  A.resize(N);
  rep(i,N) cin>>A[i];

  ll sum=0;
  for(int i=1;i<N;i++){
      if(A[i-1]<A[i]) sum+=A[i]-A[i-1];
      else sum+=(M-A[i-1])+A[i];

      if(A[i-1]+1==A[i]) continue;

      int tar=A[i];
      if(A[i-1]>A[i]) tar+=M;

      imos[A[i-1]+2]--;
      imos[tar+1]+=(tar-(A[i-1]));
      imos[tar+2]-=(tar-(A[i-1])-1);
  }

  for(int i=1;i<=2*M;i++) imos[i]+=imos[i-1];
  for(int i=1;i<=2*M;i++) imos[i]+=imos[i-1];

  ll ans=sum;
  for(int i=1;i<=M;i++){
      ans=min(ans,sum+(imos[i]+imos[i+M]));
  }
  cout<<ans<<endl;

  return 0;
}
