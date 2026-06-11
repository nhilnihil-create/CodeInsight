#include<cstdio>
#include<algorithm>
using namespace std;
long long n,K;
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
long long work(long long x,long long y){
	return !y?-x:work(y,x%y)+x/y*y*2;
}
int main(){
	scanf("%lld%lld",&n,&K);
	printf("%lld\n",n+work(K,n-K));
	return 0;
}