#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
#define int long long
//template
std::vector<int> imos(234567,0);
//main
signed main(){
  int N,M;cin>>N>>M;
  std::vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i],v[i]--;
  int sum=0;
  for(int i=1;i<N;i++){
    int low=v[i-1],high=v[i];
    if(low>high)high+=M;sum+=high-low;
    imos[low+2]++;imos[high+1]--;
  }
  for(int i=0;i<234566;i++)imos[i+1]+=imos[i];
  for(int i=1;i<N;i++){
    int low=v[i-1],high=v[i];
    if(low>high)high+=M;
    imos[high+1]-=high-low-1;
  }
  for(int i=0;i<234566;i++)imos[i+1]+=imos[i];
  int mx=0;
  std::vector<int> happy(M,0);
  for(int i=0;i<234566;i++)happy[i%M]+=imos[i];
  for(int i=0;i<M;i++)mx=max(mx,happy[i]);
  cout<<sum-mx<<endl;
}
