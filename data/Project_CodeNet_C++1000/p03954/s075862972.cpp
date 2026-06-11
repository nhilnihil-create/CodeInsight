#include<cstdio>
#define mid (L+R>>1)
using namespace std;
const int maxm=200005;
int n,m,a[maxm];
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int ret=0;bool f=0;char ch=nc();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=nc();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=nc();
	return f?-ret:ret;
}
bool check(int x){
	int now=a[n]<x;
	for (int i=n-1,j=n+1;i;i--,j++,now^=1)
	if((a[i]>=x)!=now||(a[j]>=x)!=now) break;
	return !now;
}
int main(){
	n=read(),m=(n<<1)-1;
	for (int i=1;i<=m;i++) a[i]=read();
	int L=1,R=m;
	while(L<=R) if(check(mid)) L=mid+1;else R=mid-1;
	printf("%d\n",R);
	return 0;
}