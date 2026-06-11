#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const int INF=1e9;
const long long LINF=1e18;
#define int long long
//template
template <typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
//main
signed main(){
  int N,M;cin>>N>>M;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  if(M==1)fin(N/2);
  std::vector<int> w(M,0);
  for(int i=0;i<N;i++)w[v[i]%M]++;
  int ans=0;
  std::vector<int> use(M,0);
  for(int i=1;i<(M+1)/2;i++){
    int res=min(w[i],w[M-i]);
    ans+=res;use[i]+=res;use[M-i]+=res;
  }
  ans+=w[0]/2;
  if((M&1)==0)ans+=w[M/2]/2;
  map<int,int> m;
  for(int i=0;i<N;i++)m[v[i]]++;
  std::vector<int> no(M);
  for(auto p:m)if(p.second&1)no[p.first%M]++;
  for(int i=1;i<M;i++){
    if((M&1)==0&&i==M/2)continue;
    ans+=(w[i]-max(no[i],use[i]))/2;
  }
  fin(ans);
}
