#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
vector<bool>seen;
ll N,M;
int main(){
  cin>>N>>M;
  Graph G(N);
  seen.resize(N,false);
  for(ll i=0;i<M;i++){
  ll a,b;cin>>a>>b;a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }vector<ll>A;
  queue<ll>que;que.push(0);
  while(!que.empty()){
  ll v=que.front();seen[v]=true;A.push_back(v);
    que.pop();
    for(auto u:G[v]){
      if(seen[u])
        continue;
      que.push(u);break;
      }
   }vector<ll>B;queue<ll>que1;que1.push(0);
   while(!que1.empty()){
  ll v=que1.front();seen[v]=true;B.push_back(v);
    que1.pop();
    for(auto u:G[v]){
      if(seen[u])
        continue;
      que1.push(u);break;
      }
   }ll m=A.size()+B.size()-1;
  cout<<m<<endl;
  vector<ll>ans;
  for(ll i=B.size()-1;1<=i;i--)
    ans.push_back(B[i]);
  for(ll i=0;i<A.size();i++)
    ans.push_back(A[i]);
  for(ll i=0;i<ans.size()-1;i++)
    cout<<ans[i]+1<<" ";
  cout<<ans[m-1]+1<<endl;
  
  return 0;
}