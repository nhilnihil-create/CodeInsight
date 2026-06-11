#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int N;
vector<ll> A;

int main(){
  cin>>N;
  A.resize(N);
  rep(i,N) cin>>A[i];

  vector<pair<ll,int>> v;
  for(int i=0;i<N;i++) v.push_back(mkp(A[i],i));
  v.push_back(mkp(0,MOD));
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());

  vector<ll> ans(N,0);
  int mi=v[0].second;
  ll pre=v[0].first;
  for(int i=1;i<v.size();i++){
      if(v[i].first!=pre){
          ans[mi]+=i*(pre-v[i].first);
          pre=v[i].first;
      }
      mi=min(mi,v[i].second);
  }

  for(int i=0;i<N;i++) cout<<ans[i]<<endl;

  return 0;
}
