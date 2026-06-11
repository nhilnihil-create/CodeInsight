#include <bits/stdc++.h>
using namespace std;

vector<int> G[100010];
vector<int> T[100010];

void gtot(int c,int p){
  for(int i:G[c]){
    if(i==p)continue;
    gtot(i,c);
  }
  T[p].push_back(c);
}

int xortree(int x){
  int a=0;
  if(T[x].size()==0){
    return 1;
  }
  if(T[x].size()==1){
    a=xortree(T[x][0])+1;
    return a;
  }
  for(int i:T[x]){
    a^=xortree(i);
  }
  return a+1;
}

int main(){
  int N,a,b;
  cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  gtot(1,0);
  if(xortree(1)-1)cout<<"Alice"<<endl;
  else cout<<"Bob"<<endl;
}