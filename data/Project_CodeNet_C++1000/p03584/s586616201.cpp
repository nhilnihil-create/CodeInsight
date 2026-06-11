#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int pw(int n,int k){
  int res=1;
  while(k){
    if(k&1)res*=n;res%=MOD;
    n*=n;n%=MOD;
    k>>=1;
  }
  return res;
}
//main
signed main(){
  int N,K;cin>>N>>K;
  std::vector<int> v(N),w(N),nk;
  for(int i=0;i<N;i++)cin>>w[i]>>v[i];
  int a=0,b=1;
  nk.push_back(K);
  while(b<=K){
    int res=0;
    if(K>>a&1){
      res=(K&(~(b*2-1)))|(b-1);
      //cout<<a<<" "<<b<<" "<<res<<endl;
      nk.push_back(res);
    }
    a++;b*=2;
  }
  int fans=0;
  for(int p:nk){
    int ans=0;
    for(int i=0;i<N;i++)if((p|w[i])<=p)ans+=v[i];
    //cout<<p<<" "<<ans<<endl;
    fans=max(ans,fans);
  }
  cout<<fans<<endl;
}
