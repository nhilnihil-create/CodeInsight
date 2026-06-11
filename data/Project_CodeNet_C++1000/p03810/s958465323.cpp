#include<bits/stdc++.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int n,a[100007];
bool chk(){
	int c0=0;
	for(int i=0;i<n;++i)c0+=~a[i]&1;
	if(~n&1)return c0&1;
	if(c0&1)return 1;
	if(c0==n-1){
		int p,g=0;
		for(int i=0;i<n;++i)if(a[i]&1)p=i;
		if(a[p]==1)return 0;
		--a[p];
		for(int i=0;i<n;++i)g=gcd(a[i],g);
		if(g==1)return 0;
		for(int i=0;i<n;++i)a[i]/=g;
		return !chk();
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	puts(chk()?"First":"Second");
	return 0;
}