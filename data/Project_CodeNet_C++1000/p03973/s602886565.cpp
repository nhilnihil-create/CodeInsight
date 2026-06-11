#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int A[101010];

int main(){
  int N; cin>>N;
  rep(i,N) cin>>A[i];
  ll ans=A[0]-1;
  int lim=2;
  for(int i=1;i<N;i++){
    if(A[i]==lim) lim++;
    else if(A[i]>lim){
      ans+=A[i]/lim-(A[i]%lim==0);
    }
  }
  cout<<ans<<endl;
  return 0;
}
