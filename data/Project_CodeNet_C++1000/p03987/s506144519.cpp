#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<int>p(N);
  for(int i=1;i<=N;i++){
    int a;
    cin>>a;
    p[a]=i;
  }
  ll ans=0;
  set<ll>used={0,N+1};
  for(int i=1;i<=N;i++){
    auto itr=used.lower_bound(p[i]);
    ll r=*itr;
    ll l=*(--itr);
    ans+=i*(p[i]-l)*(r-p[i]);
    used.insert(p[i]);
  }
  cout<<ans<<endl;
  return 0;
}
