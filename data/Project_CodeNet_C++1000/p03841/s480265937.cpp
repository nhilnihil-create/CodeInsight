#include<bits/stdc++.h>
using namespace std;
#define N 1111116

int n,a[N],b[N],ans[N];

bool cmp(int x,int y) {return a[x]<a[y];}

int read(){
	int x=0,f=1;char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f;
	for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return x*f;
}

int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=read();b[i]=i;
		ans[a[i]]=i;
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1,t=1;i<=n;i++)
		for (int j=1;j<=b[i]-1;j++){
			while (ans[t]) t++;ans[t]=b[i];
			if (t>a[b[i]]) {printf("No\n");return 0;}
		}
	for (int i=n,t=n*n;i>=1;i--)
		for (int j=1;j<=n-b[i];j++){
			while (ans[t]) t--;ans[t]=b[i];
			if (t<a[b[i]]) {printf("No\n");return 0;}
		}
	printf("Yes\n");
	for (int i=1;i<=n*n;i++)
		printf((i!=n*n)?"%d ":"%d\n",ans[i]);
	return 0; 
}