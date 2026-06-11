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
  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  int ans=1;
  v[0]=1;
  int res=N;int c=0;
  for(int i=1;i<N;i++){
    v[i]=min(v[i],v[i-1]+2);
    if(v[i]==v[i-1]+1){
      ans*=(i+1-c);ans%=MOD;
      v[i]=v[i-1];
      res--;c++;
    }
  }
  for(int i=2;i<=res;i++)ans*=i,ans%=MOD;
  cout<<ans<<endl;
}
