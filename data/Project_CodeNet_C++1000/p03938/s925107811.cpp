#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
int n,a[20005],b[20005],c[20005],d[20005];
int main(){
	n=read();
	for(int i=0;i<n;i++)
		c[i]=read(),d[c[i]-1]=i;
	for(int i=0;i<n;i++)
		a[i]=25000*(i+1),b[i]=d[i]+25000*(n-i);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	puts("");
	for(int i=0;i<n;i++)
		printf("%d ",b[i]);
	return 0;
}