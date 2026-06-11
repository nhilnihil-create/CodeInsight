#include<bits/stdc++.h> //Ithea Myse Valgulious
using namespace std;
const int yuzu=2e5;
typedef pair<int,int> pii;
typedef int fuko[yuzu|10];
fuko ans;
map<pii,int> mp;
int n,k,l;

struct dsu{
fuko fa;
void init(int n){
  for (int i=1;i<=n;++i) fa[i]=i;
  }
int find(int x){
  return fa[x]==x?x:fa[x]=find(fa[x]);
  }
void mg(int u,int v){
  fa[find(u)]=find(v);
  }
}gl,tl;

int main(){
int i;
scanf("%d%d%d",&n,&k,&l);
gl.init(n),tl.init(n);
for (i=1;i<=k;++i){
  int u,v;
  scanf("%d%d",&u,&v);
  gl.mg(u,v);
  }
for (i=1;i<=l;++i){
  int u,v;
  scanf("%d%d",&u,&v);
  tl.mg(u,v);
  }
for (i=1;i<=n;++i){
  mp[pii(gl.find(i),tl.find(i))]++; 
  }
for (i=1;i<=n;++i){
  printf("%d ",mp[pii(gl.find(i),tl.find(i))]);
  }
}