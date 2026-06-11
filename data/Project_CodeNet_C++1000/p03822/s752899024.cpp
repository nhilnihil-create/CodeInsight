#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define DBG_N(hoge) cerr<<"!"<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
vvi E(210000);
vvi jisuu(210000);
ll dp[210000];
bool used[210000];
ll dfs(ll now){
  if(dp[now])return dp[now];
  if(E[now].size()==0)return 0;
  vi num;
  for(int i=0;i<E[now].size();i++){
    num.pb(dfs(E[now][i]));
  }
  ll plus=0;
  ll nnum=0;
  sort(ALL(num));
  for(int i=0;i<num.size();i++){
    if(i==0){
      nnum=num[i];
    }else{
      if(nnum>=num[i]){
	nnum++;
      }else{
	nnum=num[i];
      }
    }
   
  }
  return dp[now]=nnum+1;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  for(int i=2;i<=n;i++){
    ll a;cin>>a;
    E[a].pb(i);
  }
  dfs(1);
  cout<<dp[1]<<endl;
  return 0;
}
