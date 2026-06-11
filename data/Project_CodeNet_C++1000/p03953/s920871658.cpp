#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define LL long long
using namespace std;
const int N=1e5+10;
int n,x[N],m,a[N],di[N],top,stk[N],pos[N],vis[N];
LL k,ans[N];
template<typename I> inline void read(I &ot){
	I ch=getchar(), x=0, f=1;
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();	}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0'; ch=getchar();	}
	ot=x*f;}
template<typename I, typename... U> inline void read(I &x,U&... y){read(x); read(y...);}
template<typename I>inline void swp(I&a,I&b){a^=b; b^=a; a^=b;}
int main()
{
	//freopen("Rabbit Exercise.in","r",stdin);
	read(n);
	for(RG int i=1;i<=n;i++) read(x[i]), di[i]=x[i]-x[i-1], pos[i]=i;
	read(m,k);
	for(RG int i=1;i<=m;i++) read(a[i]), swp(pos[a[i]],pos[a[i]+1]);
	for(RG int i=1;i<=n;i++)
	 if(!vis[i])
	 {
		top=0;
		for(RG int j=i;!vis[j];j=pos[j]) stk[++top]=j, vis[j]=1;
		for(RG int j=1;j<=top;j++) ans[stk[j]]=di[stk[(LL)(j+k-1)%top+1]];
	 }
	for(RG int i=1;i<=n;i++) printf("%lld\n",ans[i]+=ans[i-1]);
	return 0;
}