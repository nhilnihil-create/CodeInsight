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
  if (!x) return 0&pc(48);
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
int a[999];
int main(){
int i,u=0,v=0,n=read(),m=read();
for (i=1;i<=m;++i){
  a[i]=read();
  if (a[i]&1){
    if (!u) u=i;
    else if (!v) v=i;
    else return puts("Impossible"),0;
    }
  }
if (u) swap(a[1],a[u]);
if (v) swap(a[v],a[m]);
for (i=1;i<=m;++i) write(a[i]),p32;pl;
if (m<2) ++m;
a[1]--,a[m]++;
int j=a[1]?1:2;
cout<<m-j+1<<endl;
for (i=j;i<=m;++i) cout<<a[i]<<" ";
}