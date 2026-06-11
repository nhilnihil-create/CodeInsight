#include<stdio.h>
#include<bitset>
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int maxn=1e5+1000;
int n,m,pos[maxn],x[maxn],cf[maxn],a,s[maxn];
long long ans[maxn],k;
bitset <maxn> vis;
inline void swap(int &a,int &b){int c=a;a=b;b=c;}
signed main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&x[i]);
		pos[i]=i;
		cf[i]=x[i]-x[i-1];
	}
	scanf("%d%lld",&m,&k);
	For(i,1,m){
		scanf("%d",&a);
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
		printf("%lld.0\n",ans[i]);
	}
	return 0;
}