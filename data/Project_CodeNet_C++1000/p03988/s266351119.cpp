#include<cstdio>
#define no {puts("Impossible");return 0;}
using namespace std;
int n,m,a[1005];
inline int read(){
	int ret=0;bool f=0;char ch=getchar();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return f?-ret:ret;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		if(x>m) m=x;
		a[x]++;
	}
	for (int i=m+3>>1;i<=m;i++) if(a[i]<2) no
	a[(m+1>>1)]-=(m&1)+1;
	for (int i=m+1>>1;i;i--) if(a[i]) no
	puts("Possible");return 0;
}