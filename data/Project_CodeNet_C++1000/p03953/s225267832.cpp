#include<bits/stdc++.h>
using namespace std;
int n,m,To[100005];
int a[100005],d[100005],to[65][100005],pos[100005];
long long k,f[100005];

long long read(){
	long long x=0,w=0;char ch=getchar();
	while(!isdigit(ch)) w|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}

void print(long long x){
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}

int main(){
	n=read();
	for(int i=1;i<=n;i++) f[i]=read();
	m=read(),k=read();
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=n;i++) d[i]=f[i]-f[i-1],pos[i]=i;
	for(int i=1;i<=m;i++) swap(pos[a[i]],pos[a[i]+1]);
	for(int i=1;i<=n;i++) to[0][pos[i]]=i;
	for(int i=1;i<=64;i++){
		for(int j=1;j<=n;j++) to[i][j]=to[i-1][to[i-1][j]];
	}
	int bit=0;
	for(int i=1;i<=n;i++) To[i]=i;
	while(k){
		if(k&1) for(int i=1;i<=n;i++) To[i]=to[bit][To[i]];
		k/=2,bit++;
	}
	for(int i=1;i<=n;i++) f[To[i]]=d[i];
	for(int i=1;i<=n;i++) f[i]+=f[i-1];
	for(int i=1;i<=n;i++){
		if(f[i]<0) putchar('-'),f[i]=-f[i];
		print(f[i]),putchar('.'),putchar('0'),puts("");
	}
	
	return 0;
}