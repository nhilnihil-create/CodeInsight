#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> P2;
ll dist[105][105]={0};
ll inf=17441744174417;
int main(){
  ll n,m;
  cin>>n>>m;
  vector<P2> node;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) dist[i][j]=0;
      else dist[i][j]=inf;
    }
  }
  for(int i=0;i<m;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    node.push_back(P2(P(a,b),c));
    dist[a][b]=c;
    dist[b][a]=c;
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }
  ll ans=0;
  for(int k=0;k<m;k++){
    ll s=node[k].first.first,t=node[k].first.second,cos=node[k].second;
    bool f=false;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(dist[i][j]==dist[i][s]+cos+dist[t][j]) f=true;
      }
    }
    if(!f) ans++;
  }
  cout<<ans<<endl;
}
