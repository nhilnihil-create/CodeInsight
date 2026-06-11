#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 100010
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int n,a[N];
ll sum=0;
inline int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),sum+=a[i];
	if(n%2==0){
		puts(sum&1?"First":"Second");return 0;
	}if(sum%2==0){puts("First");return 0;}
	while(1){
		bool flag=0;int g=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1||(a[i]&1&&flag)){puts("Second");return 0;}
			if(a[i]&1){a[i]--;flag=1;}
			g=gcd(g,a[i]);
		}if((sum/=g)%2==0){puts("Second");return 0;}
		for(int i=1;i<=n;++i) a[i]/=g;
		flag=0;g=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1||(a[i]&1&&flag)){puts("First");return 0;}
			if(a[i]&1){a[i]--;flag=1;}
			g=gcd(g,a[i]);
		}if((sum/=g)%2==0){puts("First");return 0;}
		for(int i=1;i<=n;++i) a[i]/=g;
	}
}