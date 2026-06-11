#include<bits/stdc++.h>
using namespace std;
char *TT,*tmo,but[(1<<15)+2];
#define getc() ((TT==tmo&&(tmo=((TT=but)+fread(but,1,1<<15,stdin)),TT==tmo))?-1:*TT++)
inline int rd(){
  int x,c,f=1;while(!isdigit(c=getc()))f&=c!='-';x=c-'0';
  while(isdigit(c=getc()))x=x*10+c-'0';return f?x:-x;
}
typedef long long L;
const int N=1e5+11;
int n,a[N],c[N];
L b[N];
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	int i;
	n=rd();
	for(i=1;i<=n;++i)
		a[i]=rd();
	c[n+1]=n+1;
	for(i=n;i;--i){
		b[i]=b[i+1]+abs(a[i]);
		c[i]=a[i+1]<0?i+1:c[i+1];
	}
	L an=-LONG_LONG_MAX,tm=0;
	for(i=1;i<=n;++i){
		tm+=a[i];
		if(a[i]<0)
			an=max(an,tm+2*b[c[i]]-b[i+1]);
	}
	an=max(an,tm);
	cout<<an;
}