#include<cstdio>
using namespace std;
int n,L,a[100005],x;
inline int read(){
	int ret=0;bool f=0;char ch=getchar();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return f?-ret:ret;
}
int main(){
	n=read(),L=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	if(a[i]+a[i+1]>=L) x=i;
	puts(x?"Possible":"Impossible");
	if(x){
		for (int i=1;i<x;i++) printf("%d\n",i);
		for (int i=n-1;i>x;i--) printf("%d\n",i);
		printf("%d\n",x);
	}
	return 0;
}