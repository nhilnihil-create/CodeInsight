#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> node[100005];
bool used[100005];
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++) used[i]=false;
  ll s,t;
  cin>>s>>t;
  node[s].push_back(t);
  node[t].push_back(s);
  for(int i=1;i<m;i++){
    ll a,b;
    cin>>a>>b;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  deque<int> ans;
  ans.push_front(s);
  ans.push_back(t);
  used[s]=true;
  used[t]=true;
  while(1){
    bool f1=true,f2=true;
    for(int i=0;i<node[s].size();i++){
      if(!used[node[s][i]]){
        f1=false;
        s=node[s][i];
        ans.push_front(s);
        break;
      }
    }
    used[s]=true;
    if(!f1) continue;

    for(int i=0;i<node[t].size();i++){
      if(!used[node[t][i]]){
        f2=false;
        t=node[t][i];
        ans.push_back(t);
        break;
      }
    }
    used[t]=true;
    if(!f2) continue;
    if(f1&&f2) break;
  }
  cout<<ans.size()<<endl;
  while(!ans.empty()){
    cout<<ans.front()<<" ";
    ans.pop_front();
  }
  cout<<endl;
}
