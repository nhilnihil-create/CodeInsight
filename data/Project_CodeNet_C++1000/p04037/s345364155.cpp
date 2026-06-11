#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005];
inline char nc(){
	static char buf[100000],*p1,*p2;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	int ret=0;bool f=0;char ch=nc();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=nc();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=nc();
	return f?-ret:ret;
}
bool cmp(int x,int y){return x>y;}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	int now=0;while(a[now+2]>now+1) now++;
	int x=a[now+1]-now,y=0;
	for (int i=now+1;i<=n;i++)
	if(a[i]>now) y++;else break;
	puts(x&y&1?"Second":"First");
	return 0;
}