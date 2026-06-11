#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(int i=int(x);i<int(y);++i)
#define For(i,x,y)  for(int i=int(x);i<=int(y);++i)
#define FOr(i,x,y)  for(int i=int(x);i>=int(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define LL			(long long)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,GYN,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
	void writeln(ll x){write(x);puts("");}
}using namespace SHENZHEBEI;
const ll N=400100;
ll a[N],opt[N],f[N][4],n;
ll ppow(ll x,ll k){return k?-ppow(x,k-1):x;}
int main(){
	n=read();
	For(i,1,n)	a[i]=read(),opt[i]=a[i]>0,a[i]=abs(a[i]);
	memset(f,-60,sizeof f);
	f[0][0]=0;
	For(i,1,n){
		if (!opt[i])f[i-1][2]=f[i-1][1],f[i-1][1]=f[i-1][0],f[i-1][0]=-1e18;
		For(cur,0,2)For(now,0,cur)Max(f[i][now],f[i-1][cur]+ppow(a[i],cur));
	}
	writeln(max(f[n][0],f[n][1]));
}