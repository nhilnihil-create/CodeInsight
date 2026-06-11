#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N];
ll sum,p,k;
int main(){
	n=read(),p=1LL*n*(n+1)/2;
	for(int i=1;i<=n;++i){
		sum+=a[i]=read();
	}
	if(sum%p){
		puts("NO");
		return 0;
	}
	k=sum/p;
	a[n+1]=a[1];
	for(int i=1;i<=n;++i){
		ll g=a[i]+k-a[i+1];
		if(g%n||g/n>k||a[i]<k){
			puts("NO");return 0;
		}
	}
	puts("YES");
	return 0;
}
