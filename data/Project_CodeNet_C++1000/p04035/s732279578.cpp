#include<iostream>
#include<cstdio>
using namespace std;
const int N=2002020;
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	int n=read(),L=read();
	int ps=-1,lst=0;
	for(int i=1;i<=n;i++){
		int x=read();
		if(i>1 && x+lst>=L){ps=i-1;break;}
		lst=x;
	}
	if(ps<0)puts("Impossible");
	else{
		puts("Possible");
		for(int i=1;i<ps;i++)printf("%d\n",i);
		for(int i=n-1;i>ps;i--)printf("%d\n",i);
		printf("%d\n",ps);
	}
	return 0;
}