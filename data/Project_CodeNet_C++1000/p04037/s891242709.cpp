#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
int a[MAXN];
int main(){
	int n=read();
	for (register int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n,greater<int>());
	int p=1;
	for (;p<=n;++p){
		if (a[p]<p) break;
	}
	p--;
	int cnt1=0,cnt2=0;
	for (register int i=p+1;i<=n;++i){
		//printf("i:%d a[i]:%d p:%d\n",i,a[i],p); 
		if (a[i]<p) break;
		cnt1++;
	}
//	printf("%d %d\n",a[p],p);
	cnt2=a[p]-p;
	//printf("%d %d %d\n",p,cnt1,cnt2);
	if ((cnt1&1)||(cnt2&1)) puts("First");
	else puts("Second");
}