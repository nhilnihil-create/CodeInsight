#include<stdio.h>
#include<bitset>
#include<string.h>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+1000;
int n,m,pos[maxn],x[maxn],cf[maxn],a,s[maxn];
long long ans[maxn],k;
bitset <maxn> vis;
inline void swap(int &a,int &b){int c=a;a=b;b=c;}
inline int rd(){
		int ans=0,f=1;char c=getchar();
		while(!isdigit(c)){ f^=(c=='-'); c=getchar(); }
		for(;isdigit(c);c=getchar()) ans=(ans<<1)+(ans<<3)+(c^48); return f?ans:-ans;
}
inline void pr(long long x){
    if(x<0){putchar('-');x=~(x-1);}
    int s[30],top=0;
    while(x){s[++top]=x%10;x/=10;}
    if(!top)s[++top]=0;
    while(top)putchar(s[top--]+'0');
}
signed main(){
	//scanf("%d",&n);
	n=rd();
	For(i,1,n){
		x[i]=rd();
		//scanf("%d",&x[i]);
		pos[i]=i;
		cf[i]=x[i]-x[i-1];
	}
	m=rd();scanf("%lld",&k);
	//scanf("%d%lld",&m,&k);
	For(i,1,m){
		//scanf("%d",&a);
		a=rd();
		swap(pos[a],pos[a+1]);
	}
	For(i,1,n){
		if(vis[i]){
			continue ;
		}
		int cnt=0;
		for(int j=i;!vis[j];j=pos[j]) {
			s[++cnt]=j;
			vis[j]=1;
		}
		For(j,1,cnt) {
			ans[s[j]]=1ll*cf[s[(k+j-1)%cnt+1]];
		}
	}
	For(i,1,n){
		ans[i]+=ans[i-1];
		//printf("%lld.0\n",ans[i]);
		pr(ans[i]);
		putchar('.');
		putchar('0');
		putchar('\n');
	}
	return 0;
}
