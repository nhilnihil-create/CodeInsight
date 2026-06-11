#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rec register char
#define rel register ll
#define gc getchar
#define pc putchar
#define p32 pc(' ')
#define pl puts("")
/*By Citrus*/
inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return pc(48);
  if (x<0) x=-x,pc('-');
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int yuzu=1e5;
vector<int> lj[yuzu|10];
typedef int fuko[yuzu|10];
fuko d1,d2;
int n=read();

void dfs(int u,int fa,int *d){
d[u]=d[fa]+1;
for (int i:lj[u]) if (i^fa) dfs(i,u,d);
}

int main(){
int i,u,v;
for (i=1;i<n;++i){
  u=read(),v=read();
  lj[u].push_back(v);
  lj[v].push_back(u);
  }
dfs(1,0,d1),dfs(n,0,d2);
int cnt=0;
for (i=1;i<=n;++i) cnt+=d1[i]<=d2[i];
puts(cnt*2<=n?"Snuke":"Fennec");
}