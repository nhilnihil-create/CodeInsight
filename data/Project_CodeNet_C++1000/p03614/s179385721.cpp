//copied
#include<cstdio>
using namespace std;
inline char tc(void){
	static char fl[10000],*A=fl,*B=fl;
	return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline int read(void){
	int a=0;static char c;
	while((c=tc())<'0'||c>'9');
	while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
	return a;
}
int n,ans,a[100005];
int main(void){
	register int i;
	n=read();
	for(i=1;i<=n;++i)
		a[i]=read();
	for(i=1;i<=n;++i)
		if(a[i]==i)++ans,++i;
	printf("%d",ans);
	return 0;
}