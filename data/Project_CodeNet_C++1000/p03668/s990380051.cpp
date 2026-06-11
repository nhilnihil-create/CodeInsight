#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

ll n;
vector<ll> g[101010];

ll dfs(ll v,ll pre){
  ll res=0;
  for(ll nv : g[v]){
    if(nv==pre)continue;
    ll tmp=dfs(nv,v);
    res^=tmp+1;
  }
  return res;
}

int main(){
	cin>>n;
  rep(i,n-1){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b); g[b].push_back(a);
  }
  if(dfs(0,-1)==0)cout<<"Bob"<<endl;
  else cout<<"Alice"<<endl;
	return 0;
}
