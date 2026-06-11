#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define fr(i,n) for(int i=0;i++<n;)

ll n,m,a[100010],b[100010];
bool vis[100010]={0,1};
vector<ll> t[100010];
vector<ll> path;

ll r(){
  bool f[2]={0,0};
  for(auto i=t[*path.begin()].begin();i!=t[*path.begin()].end();i++){
    ll g=*i;
    if(!vis[g]) f[0]=1;
  }
  auto A=path.end();
  for(auto i=t[*(--A)].begin();i!=t[*A].end();i++){
    ll g=*i;
    if(!vis[g]) f[1]=1;
  }
  return (ll)2*f[0]+f[1];
}

void jo(ll Q){
  if(Q==1){
  auto A=path.end();
  for(auto i=t[*(--A)].begin();i!=t[*A].end();i++){
    ll g=*i;
    if(!vis[g]){
      path.push_back(g);
      vis[g]=1;
      return;
    }
  }
  }
  else{
  auto A=path.begin();
  for(auto i=t[*A].begin();i!=t[*A].end();i++){
    ll g=*i;
    if(!vis[g]){
      path.insert(path.begin(),g);
      vis[g]=1;
      return;
    }
  }
  }
}

int main(){
  cin>>n>>m;
  fr(i,m){
    cin>>a[i]>>b[i];
    t[a[i]].push_back(b[i]);
    t[b[i]].push_back(a[i]);
  }
  path.push_back(1);
  for(;;){
    auto A=path.end();
    ll R=r();
    if(R==0) break;
    jo(R%2);
  }
  cout<<path.size()<<endl;
  for(auto i=path.begin();i!=path.end();i++){
    cout<<*i<<" ";
  }
  cout<<endl;
}