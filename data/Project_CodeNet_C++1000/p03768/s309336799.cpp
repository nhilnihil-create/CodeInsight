#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll max_col[100005][15]={0};
ll nxt[100005][15]={0};
ll col[100005]={0};
ll ans[100005]={0};
vector<P> node;
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    node.push_back(P(a,b));
  }
  ll q;
  cin>>q;
  for(int i=1;i<=q;i++){
    ll v,d;
    cin>>v>>d>>col[i];
    max_col[v][d]=i;
    ans[v]=i;
  }
  for(int i=1;i<=n;i++){
    for(int j=10;j>=0;j--) max_col[i][j]=max(max_col[i][j],max_col[i][j+1]);
  }
  for(int turn=1;turn<=10;turn++){
    for(int i=1;i<=n;i++){
      for(int j=0;j<=10;j++){
        nxt[i][j]=max_col[i][j];
      }
    }
    for(int i=0;i<m;i++){
      ll s=node[i].first,t=node[i].second;
      for(int j=0;j<=10;j++){
        ll mv=max(max_col[s][j],max_col[t][j]);
        nxt[s][j]=max(nxt[s][j],mv);
        nxt[t][j]=max(nxt[t][j],mv);
      }
    }
    for(int i=1;i<=n;i++){
      for(int j=0;j<=10;j++){
        max_col[i][j]=nxt[i][j];
        nxt[i][j]=0;
      }
    }
    for(int i=1;i<=n;i++) ans[i]=max(ans[i],max_col[i][turn]);
  }
  for(int i=1;i<=n;i++) cout<<col[ans[i]]<<endl;
}
