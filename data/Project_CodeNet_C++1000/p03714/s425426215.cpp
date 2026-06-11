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
const int yuzu=3e5;
typedef ll fuko[yuzu|10];
fuko a,dp_l,dp_r;
int n=read();

priority_queue<ll,vector<ll>,greater<ll> > xiao;
priority_queue<ll> da;

void doleft(){
int i;ll sum=0;
for (i=1;i<=n*3;++i){
  xiao.push(a[i]);
  sum+=a[i];
  dp_l[i]=sum;
  if (xiao.size()>n){
    sum-=xiao.top();
    xiao.pop();
    dp_l[i]=sum;
    }
  }
}

void doright(){
int i;ll sum=0;
for (i=n*3;i;--i){
  da.push(a[i]);
  sum+=a[i];
  dp_r[i]=sum;
  if (da.size()>n){
    sum-=da.top();
    da.pop();
    dp_r[i]=sum;
    }
  }
}

int main(){
int i;
for (i=1;i<=n*3;++i) read(a[i]);
doleft(),doright();
ll ans=-1e17;
for (i=n;i<=(n<<1);++i) ans=max(dp_l[i]-dp_r[i+1],ans);
write(ans);
}