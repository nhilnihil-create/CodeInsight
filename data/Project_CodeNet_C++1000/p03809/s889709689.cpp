#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
void Y(){
  fin("YES");
}
void N(){
  fin("NO");
}
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int n;cin>>n;
  vector<int> v(n),edge[n];
  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  if(n==2){
    if(v[0]==v[1])Y();
    else N();
  }
  int root;
  for(int i=0;i<n;i++)if(edge[i].size()>1)root=i;
  vector<int> parent(n,-1),son[n];
  queue<int> que;que.push(root);
  while(que.size()){
    int p=que.front();que.pop();
    for(int q:edge[p]){
      if(parent[p]==q)continue;
      parent[q]=p;
      son[p].push_back(q);
      que.push(q);
    }
  }
  vector<int> cou(n);
  for(int i=0;i<n;i++)if((cou[i]=son[i].size())==0)que.push(i);
  while(que.size()){
    int p=que.front();que.pop();
    if(son[p].size()==1){
      if(v[p]!=v[son[p][0]])N();
    }
    if(son[p].size()>1){
      int sum=0,mx=0;
      for(int q:son[p]){
        sum+=v[q];
        chmax(mx,v[q]);
      }
      if(sum<v[p])N();
      if(sum>v[p]*2)N();
      int de=(sum-v[p]);
      if(sum-mx<de)N();
      v[p]-=de;
    }
    if(p==root){
      if(v[p])N();
      Y();
    }
    if(--cou[parent[p]]==0)que.push(parent[p]);
  }
}
