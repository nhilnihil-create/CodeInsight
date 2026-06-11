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
vvi E(222222);
ll color[222222];
//-1 black 1 white
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  for(int i=0;i<n-1;i++){
    ll a,b;cin>>a>>b;
    E[a].pb(b);
    E[b].pb(a);
  }
  queue<pair<ll,ll>>que;
  que.push(mp(1,-1));
  que.push(mp(n,1));
  color[1]=-1;
  color[n]=1;
  while(!que.empty()){
    pair<ll,ll>now=que.front();
    que.pop();
    for(auto a:E[now.F]){
      if(color[a]==0){
	color[a]=now.S;
	que.push(mp(a,now.S));
      }
    }
  }
  ll now=0;
  for(int i=1;i<=n;i++){
    // cout<<now<<endl;
    now+=color[i];
  }
  //cout<<now<<endl;
  if(now<0)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
  return 0;
}