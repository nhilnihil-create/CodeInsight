#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

// a*i+b=(xをiにしたときのスイッチの減少)
ll a[202020], b[202020];

int main(){
  int N,M; cin>>N>>M;
  ll A[N]; rep(i,N) cin>>A[i];
  ll sum=0;
  rep(i,N-1){
    bool flag=0;
    if(A[i+1]<A[i]){
      flag=1;
      A[i+1]+=M;
    }
    sum+=A[i+1]-A[i];
    if(A[i+1]-A[i]==1){
      if(flag) A[i+1]-=M;
      continue;
    }
    int s=min(A[i]+2,A[i+1]),t=A[i+1]+1;
    ll bb=-1+s;
    b[s]+=bb; b[t]-=bb;
    a[s]-=1; a[t]+=1;
    if(flag) A[i+1]-=M;
  }
  vector<ll> heru(M+1);
  for(ll i=1;i<=2*M;i++){
    a[i]+=a[i-1];
    b[i]+=b[i-1];
    heru[i%M]+=a[i]*i+b[i];
  }
  sort(heru.begin(),heru.end());
  cout<<sum+heru[0]<<endl;
  return 0;
}
