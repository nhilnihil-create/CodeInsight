#include <cstdio>
#include <algorithm>
#define IL inline
#define N 1000007
#define REP(a,b,c) for(a=b;a<=c;a++)
using namespace std;
const int mod=1e9+7;
int n,f[N],ans;
IL int rd(){
	int res=0;char c;while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();return res;
}
int main(){
	n=rd();int i,d=0,t,bs;
	if(n==1){puts("1");return 0;}
	f[0]=1;bs=1LL*(n-1)*(n-1)%mod;
	REP(i,0,n-2){
		t=f[i]=(f[i]+d)%mod;
		f[i+2]=(f[i+2]-t+mod)%mod;
		d=(t+d)%mod;
		ans=(ans+1LL*f[i]*(bs+i+1))%mod;
	}
	t=f[i]=(f[i]+d)%mod,d=(t+d)%mod;
	ans=(ans+1LL*f[i]*(n-1))%mod;i++;
	t=f[i]=(f[i]+d)%mod,ans=(ans+t)%mod;
	printf("%d\n",ans);
  return 0;
}