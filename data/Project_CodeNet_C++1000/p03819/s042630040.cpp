#include<bits/stdc++.h>
using namespace std;
const int _=1e5+7;
const int __=3e5+7;
struct com{
  int l,r,len;
}c[__];
int n,m,tr[_],ans;
bool rule(com a,com b){ return a.len<b.len; }
void add(int x,int w){
  for(int i=x;i<=m;i+=i&(-i))
    tr[i]+=w;
}
void modify(int l,int r,int w){
  add(l,w);
  add(r+1,-w);
}
int query(int x){
  int res=0;
  for(int i=x;i;i-=i&(-i))
    res+=tr[i];
  return res;
}
int main(){
  //#ifndef ONLINE_JUDGE
  //freopen("x.in","r",stdin);
  //#endif
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    scanf("%d%d",&c[i].l,&c[i].r);
    c[i].len=c[i].r-c[i].l+1;
  }
  sort(c+1,c+1+n,rule);
  int p=1;
  for(int i=1;i<=m;i++){
    while(p<=n&&c[p].len<i){
      modify(c[p].l,c[p].r,1);
      p++;
    }
    //printf("p: %d\n",p);
    ans=n-p+1;
    for(int j=i;j<=m;j+=i)
      ans+=query(j);
    printf("%d\n",ans);
  }
  return 0;
}
