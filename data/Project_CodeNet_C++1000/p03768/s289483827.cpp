#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

int n,m,q;
VVI G(101010);
VI v(101010);
VI d(101010);
VI c(101010);
VI col(101010,0);
VI rest(101010,-1);

void solve(int u,int w,int k){
  if(col[u]>0&&rest[u]>=k) return;
  if(col[u]==0) col[u]=w;
  rest[u]=k;
  for(int i:G[u]){
    if(k>0) solve(i,w,k-1);
  }
}

int main(){
  int i,j;
  cin>>n>>m;
  for(i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--; b--;
    G[a].pb(b);
    G[b].pb(a);
  }  
  cin>>q;
  for(i=0;i<q;i++){
    cin>>v[i]>>d[i]>>c[i];
    v[i]--;
  }
  for(i=q-1;i>=0;i--) solve(v[i],c[i],d[i]);
  for(i=0;i<n;i++){
    cout<<col[i]<<endl;
  }

  return 0;
}