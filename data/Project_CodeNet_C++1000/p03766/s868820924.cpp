#include<iostream>
#include<cstdio>
#include<ctype.h>
using namespace std;
const int mod=1e9+7;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
int f[1000007];
int main(){
	int n=read(),s=0;
	f[n]=n;f[n-1]=1ll*n*n%mod;
	for(int i=n-2;i>=1;--i){
		s=(s+f[i+3])%mod;
		f[i]=(f[i+1]+1ll*(n-1)*(n-1)+s+i+1)%mod;
	}
	printf("%d\n",f[1]);
	return 0;
}