#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define INF 0x3f3f3f3f3f3f3f3fLL

char s[2];
LL n,x,f[3],g[3];

void upd(LL x,LL &y){y=max(y,x);}

int main(){
	scanf("%lld",&n);
	scanf("%lld",&x); f[0]=x; f[1]=f[2]=-INF;
	for (LL i=1;i<n;++i){
		g[0]=f[0]; g[1]=f[1]; g[2]=f[2];
		f[0]=f[1]=f[2]=-INF;
		scanf("%s%lld",s,&x);
		if (s[0]=='-'){
			upd(g[0]-x,f[0]);
			upd(g[0]-x,f[1]);
			upd(g[1]+x,f[0]);
			upd(g[1]+x,f[1]);
			upd(g[1]+x,f[2]);
			upd(g[2]-x,f[1]);
			upd(g[2]-x,f[2]);
		}
		else{
			upd(g[0]+x,f[0]);
			upd(g[1]-x,f[0]);
			upd(g[1]-x,f[1]);
			upd(g[2]+x,f[1]);
			upd(g[2]+x,f[2]);
		}
	}
	printf("%lld\n",f[0]);
	
	return 0;
}
			