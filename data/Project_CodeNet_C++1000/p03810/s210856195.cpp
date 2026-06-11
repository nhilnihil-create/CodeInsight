#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
typedef long long ll;
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
int n,odd,a[N];
ll sum;
bool dfs(){
	int odd=0;
	bool flag=false;
	for(int i=1;i<=n;++i){
		if(a[i]&1)++odd;
		if(a[i]==1)flag=true;
	}
	if((n-odd)&1)return true;
	if(flag||odd>1)return false;
	int g=0;
	for(int i=1;i<=n;++i){
		if(a[i]&1)--a[i];
		g=__gcd(a[i],g);
	}
	for(int i=1;i<=n;++i){
		a[i]/=g;
	}
	return dfs()^1;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	puts(dfs()?"First":"Second");
	return 0;
}
