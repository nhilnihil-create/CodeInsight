#include<bits/stdc++.h>
#define maxn 100005
#define LL long long
using namespace std;
char cb[1<<20],*cs,*ct;
#define getc() (cs==ct&&(ct=(cs=cb)+fread(cb,1,1<<20,stdin),cs==ct)?0:*cs++)
template<class T>inline void read(T &a){
	char c;bool f=0;while(!isdigit(c=getc())) c=='-'&&(f=1);
	for(a=c-'0';isdigit(c=getc());a=a*10+c-'0'); f&&(a=-a);
}
int n;
LL F[maxn],G[maxn],a[maxn];
int main()
{
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(i>1&&a[i-1]>0&&a[i]>0) a[i-1]+=a[i],i--,n--;
	}
	for(int i=1;i<=n;i++) F[i]=F[i-1]+a[i],G[i]=G[i-1]+abs(a[i]);
	LL ans=F[n];
	for(int i=2;i<n;i++) if(a[i]<0) ans=max(ans,F[i]-a[i+1]+G[n]-G[i+1]);
	printf("%lld\n",ans);
}