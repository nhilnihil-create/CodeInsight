#include <bits/stdc++.h>
#define il inline
#define RG register
#define ll long long
#define lb(x) (x & -x)
#define N (500005)

using namespace std;

struct data{ int l,r,len; }q[N];

int c[N],n,m;

il int gi(){
  RG int x=0,q=1; RG char ch=getchar();
  while ((ch<'0' || ch>'9') && ch!='-') ch=getchar();
  if (ch=='-') q=-1,ch=getchar();
  while (ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
  return q*x;
}

il int cmp(const data &a,const data &b){ return a.len<b.len; }

il void add(RG int x,RG int v){
  for (;x<=m;x+=lb(x)) c[x]+=v; return;
}

il int query(RG int x){
  RG int res=0; for (;x;x^=lb(x)) res+=c[x]; return res;
}

int main(){
  n=gi(),m=gi();
  for (RG int i=1;i<=n;++i) q[i].l=gi(),q[i].r=gi(),q[i].len=q[i].r-q[i].l+1;
  sort(q+1,q+n+1,cmp);
  for (RG int i=1,pos=0,ans;i<=m;++i){
    while (pos<n && q[pos+1].len<i) add(q[++pos].l,1),add(q[pos].r+1,-1);
    ans=n-pos; for (RG int j=i;j<=m;j+=i) ans+=query(j); printf("%d\n",ans);
  }
  return 0;
}
