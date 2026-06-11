#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<int, int> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  vector<P>iti(N);
  ll memo[N][2];
  rep(i,N){memo[i][0]=0ll;memo[i][1]=0ll;}
  rep(i,N){
    cin>>A[i];
    A[i]--;
    iti[i]=P(A[i],i);
  }
  sort(iti.begin(),iti.end());
  set<int>st1;
  set<int>st2;
  st1.insert(1);
  st2.insert(N);
  rep(i,N){
    auto t=*st1.lower_bound(-1*iti[i].second);
    memo[i][0]=t+iti[i].second;
    st1.insert(-1*iti[i].second);
  }
  rep(i,N){
    auto t=*st2.lower_bound(iti[i].second);
    memo[i][1]=t-iti[i].second;
    st2.insert(iti[i].second);
  }
  ll ans=0ll;
  rep(i,N){
    ll x=memo[i][0]*memo[i][1];
    ans+=x*(i+1ll);
  }
  cout<<ans;
  
}
