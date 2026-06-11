#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mx,n,i,j,now,ha,len,m,b[1010],c[1010],fac[1010];
int main(){
	scanf("%lld",&n);
	fac[0]=1;
	for(i=1;i<=50;i++)fac[i]=fac[i-1]*2;
	mx=50;
	while(fac[mx]>n)mx--;
	n-=fac[mx];
	m=mx;
	//printf("%lld\n",mx);
	len=m*2;
	now=m;
	c[++ha]=now+1;
	c[++ha]=now+1;
	now++;
	len+=2;
	while(n){
		while(fac[mx]>n)mx--;
		n-=fac[mx];
		b[mx]=++now;
		c[++ha]=now;
		len+=2;
	}
	printf("%lld\n",len);
	for(i=0;i<=m;i++){
		if(i)printf("%lld ",i);
		if(b[i])printf("%lld ",b[i]);
	}
	for(i=1;i<=m;i++)printf("%lld ",i);
	for(i=1;i<=ha;i++)printf("%lld ",c[i]);
}