#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
#define Max(a) (*max_element(ALL(a)))
#define Min(a) (*min_element(ALL(a)))
using namespace std;
struct edge{
  ll to,cost;
};
vector<vector<edge>>E(222222);
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  for(int i=0;i<n-1;i++){
    ll a,b,c;cin>>a>>b>>c;
    E[--a].pb({--b,c});
    E[b].pb({a,c});
  }
  ll q,k;cin>>q>>k;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>que;
  que.push(mp(0,k-1));
  vi dp(222222,llINF);
  dp[k-1] = 0;
  while(!que.empty()){
    ll now = que.top().S;
    que.pop();
    for(auto e:E[now]){
      if(dp[e.to] > dp[now] + e.cost){
	dp[e.to] = dp[now] + e.cost;
	que.push(mp(dp[e.to],e.to));
      }
    }
  }
  while(q--){
    ll x,y;cin>>x>>y;
    cout<<dp[x-1]+dp[y-1]<<endl;
  }
  return 0;
}
