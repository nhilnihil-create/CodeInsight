#include<bits/stdc++.h>
using namespace std;
int find(int x);
int same(int x,int y);
void unite(int x,int y);
int qfind(int x);
int qsame(int x,int y);
void qunite(int x,int y);
int p[200009];
int q[200009];
map<int,int>mp[200009];

int main(){
  int n,k,l;
  cin>>n>>k>>l;
  for(int i=0;i<=n;i++){
    p[i]=i;
    q[i]=i;
  }
  for(int i=0;i<k;i++){
    int a,b;
    cin>>a>>b;
    if(!same(a,b)){
      unite(a,b);
    }
  }
  for(int i=0;i<l;i++){
    int a,b;
    cin>>a>>b;
    if(!qsame(a,b)){
      qunite(a,b);
    }
  }
  for(int i=1;i<=n;i++){
    mp[find(i)][qfind(i)]++;
  }
  for(int i=1;i<=n;i++){
    cout<<mp[find(i)][qfind(i)];
    if(i==n)cout<<endl;
    else cout<<' ';
  }
  return(0);
}

int find(int x){
  if(p[x]==x)return x;
  return p[x]=find(p[x]);
}

int same(int x,int y){
  if(find(x)==find(y))return 1;
  return 0;
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  p[x]=y;
}

int qfind(int x){
  if(q[x]==x)return x;
  return q[x]=qfind(q[x]);
}

int qsame(int x,int y){
  if(qfind(x)==qfind(y))return 1;
  return 0;
}

void qunite(int x,int y){
  x=qfind(x);
  y=qfind(y);
  q[x]=y;
}
