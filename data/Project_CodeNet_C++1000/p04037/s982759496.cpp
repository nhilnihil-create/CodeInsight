#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[100005],f[100005],nxt[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[n+1]=-1;
	for(int i=n;i;i--){
		nxt[i]=i;
		if(a[i]==a[i+1]) nxt[i]=nxt[i+1];
	}
	f[0]=1;
	for(int i=1,pre=0;i<=n;i++){
		if(a[i]!=a[i-1]) pre=a[i-1];
		else{
			f[i]=f[i-1];continue;
		}
		int w=a[i]+n-i;
		f[i]=!(w&1);
		if(f[i]){
			if(pre>n-i+1) f[i]=f[i-1];
			else if(n-nxt[i]>a[i]) f[i]=2;
		}else{
			if(pre>=n-i+1) f[i]=f[i-1];
			else if(n-nxt[i]>=a[i]) f[i]=2;
		}
	}
	f[n+1]=0;
	for(int i=n;i;i--){
		if(f[i]==2) f[i]=f[i+1];
		if(f[i]==1) return puts("First"),0;
	}
	puts("Second");
	return 0;
}