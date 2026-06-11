#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#define int long long
using namespace std;
inline int read(){
	int x=0,w=0;char c=getchar();
	while(!isdigit(c))w|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}
int a,b,ans;
signed main(){
	a=ans=read();b=read();
	b=min(b,a-b);
	a=a-b;
	do{
		ans+=b*2*(a/b);
		int t=a;
		a=b;
		b=t%b;
	}while(b);
	printf("%lld",ans-a);
	return 0;
}