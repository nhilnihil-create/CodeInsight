#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll A[101010],B[101010];
int N;
ll K;

ll solve(int ind,int bit){
  for(int i=bit+1;i<31;i++){
    if(((K>>i)&1)==0 && ((A[ind]>>i)&1)==1) return 0;
  }
  return B[ind];
}

int main(){
  cin>>N>>K;
  rep(i,N) cin>>A[i]>>B[i];
  ll ans=0;
  rep(i,N){
    bool flag=1;
    rep(j,31) if(((A[i]>>j)&1)==1 && ((K>>j)&1)==0){
      flag=0;
      break;
    }
    if(flag) ans+=B[i];
  }
  rep(i,31) if((K>>i)&1){
    ll tmp=0;
    rep(j,N) if(((A[j]>>i)&1)==0){
      tmp+=solve(j,i);
    }
    ans=max(ans,tmp);
  }
  cout<<ans<<endl;
  return 0;
}
