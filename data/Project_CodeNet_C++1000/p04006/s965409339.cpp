#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,x;
  cin>>N>>x;
  vector<int64_t> a(N);
  for(int i=0;i<N;++i) cin>>a[i];

  //K回転して揃えるときの最小値
  int64_t ans=0;
  for(int i=0;i<N;++i) ans += a[i];
  
  vector<int64_t> b=a;
  for(int K=1;K<N;++K){
    int64_t subans=0;
    for(int i=0;i<N;++i){
      b[i]=min(b[i],a[(i+(N-K))%N]);
      subans += b[i];
    }
    ans=min(ans,subans+K*x);
  }

  cout<<ans<<endl;
}
