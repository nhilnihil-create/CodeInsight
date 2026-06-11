#include<bits/stdc++.h>
#define maxn 505
using namespace std;
int n,x[maxn],a[maxn*maxn],c[maxn];
bool solve(){
	for(int i=1;i<=n*n;i++){
		for(int j=1;j<=n;j++) if(x[j]==i){
			if(++c[j]<j) return 0;
			a[i]=j; break;
		}
		if(a[i]) continue;
		int k=0;
		for(int j=1;j<=n;j++) if(x[j]>i&&c[j]<j-1&&x[j]<x[k]) k=j;
		if(k) {c[a[i]=k]++;continue;}
		for(int j=1;j<=n;j++) if(x[j]<i&&c[j]<n) {k=j;break;}
		if(k) c[a[i]=k]++;
		else return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]); x[0]=n*n+1;
	if(!solve()) return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n*n;i++) printf("%d%c",a[i],i==n*n?10:32);
}