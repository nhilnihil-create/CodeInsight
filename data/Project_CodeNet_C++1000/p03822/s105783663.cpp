#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
typedef long long ll;
typedef multiset<ll> S;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
const ll inf=1001001001001001;
const int INF=1001001001;
const int mod=1000000007;
bool chmin(auto &a,auto b){if(a>b){a=b;return true;}return false;}
bool chmax(auto &a,auto b){if(a<b){a=b;return true;}return false;}
int n;
vi depth;
vvi v;
void dfs(int i){
  vi k;int a=0;
  for(int x:v[i]){
    if(depth[x]==inf)dfs(x);
    k.pb(depth[x]);
  }
  sort(all(k));
  reverse(all(k));
  rep(i,k.size())chmax(a,k[i]+i+1);
  depth[i]=a;
}

int main(){
    cin>>n;
  v=vvi(n);
  REP(i,1,n){
    int a;cin>>a;a--;
    v[a].pb(i);
  }
  depth=vi(n);
  rep(i,n)depth[i]=inf;
  dfs(0);
  cout<<depth[0]<<endl;
}