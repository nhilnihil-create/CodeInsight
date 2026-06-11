#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N,L;
  cin>>N>>L;
  vector<ll>a(N);
  for(int i=0;i<N;i++)cin>>a[i];
  vector<int>ans;
  bool ok=false;
  for(int i=0;i<N-1;i++){
    if(a[i]+a[i+1]>=L){
      ok=true;
      for(int j=1;j<i+1;j++)ans.push_back(j);
      for(int j=N-1;j>=i+1;j--)ans.push_back(j);
      break;
    }
  }
  if(ok){
    cout<<"Possible"<<endl;
    for(auto it:ans)cout<<it<<endl;
  }
  else cout<<"Impossible"<<endl;
  return 0;
}
