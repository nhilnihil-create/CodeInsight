/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2005;

int n,cst;
int val[N],now[N];

inline int Ri(){
	register int r=0,c=getchar();
	while(c<'0' || '9'<c) c=getchar();
	while('0'<=c && c<='9') r=(r<<1)+(r<<3)+c-'0',c=getchar();
	return r;
}
int main(){
	n=Ri(),cst=Ri();
	for(int i=1;i<=n;i++) now[i]=val[i]=Ri();
	long long ans=-1;
	for(int r=0;r<n;r++){
		long long tot=1ll*r*cst;
		for(int i=1;i<=n;i++)
			tot+=(now[i]=min(now[i],val[i+r>n? i+r-n:i+r]));
		if(ans==-1) ans=tot;
		else ans=min(ans,tot);
	}
	printf("%lld\n",ans);
	return 0;
}