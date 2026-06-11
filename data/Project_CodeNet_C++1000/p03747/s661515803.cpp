#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,l,t,x[N],w[N],cnt;

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();l=read();t=read();
	for (int i=0;i<n;i++) x[i]=read(),w[i]=read();
	for (int i=0;i<n;i++){
		x[i]+=(w[i]==1)?t:-t;
		cnt=(cnt+x[i]/l)%n;x[i]%=l;
		if (x[i]<0) cnt--,x[i]+=l;
	}	
	sort(x,x+n);
	for (int i=0;i<n;i++)
		printf("%d\n",x[((i+cnt)%n+n)%n]);
	return 0;
}