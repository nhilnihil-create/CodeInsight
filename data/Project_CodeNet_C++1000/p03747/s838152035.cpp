#include<iostream>
#include<cstdio>
#include<ctype.h>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
int x[100007];
int main(){
	int n=read(),l=read(),t=read(),c=0;
	for(int i=1;i<=n;++i){
		int r=read()+(-2*read()+3)*t;
		if(r>0)(c+=r/l)%=n;
		else if(r)(c+=(r+1)/l-1)%=n;
		x[i]=(r%l+l)%l;
	}
	sort(x+1,x+n+1);
	c=(c+n)%n;
	for(int i=c+1;i<=n;++i)printf("%d\n",x[i]);
	for(int i=1;i<=c;++i)printf("%d\n",x[i]);
	return 0;
}