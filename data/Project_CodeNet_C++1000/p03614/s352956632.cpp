#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define rep(i,N) for(int i=0;i<N;i++)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>p(N);
  for(auto&it:p)cin>>it;
  ll ans=0;
  for(int i=0;i<N;i++){
    if(p[i]==i+1){
      ans++;
      if(i+1<N&&p[i+1]==i+2)i++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
