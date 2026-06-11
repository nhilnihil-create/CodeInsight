#include<bits/stdc++.h>
using namespace std;
long long n,i,j,k,l,a[100005],b[100005],du[100005],flag,y,z;
long long top,nex[200005],to[200005],fir[100005];
long long read(){
	char ch=getchar();
	long long x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int lj(long long u,long long v){
	top++;
	nex[top]=fir[u];
	fir[u]=top;
	to[top]=v;
	return 0;
}
int ss(long long u,long long v){
	if(flag==1)
		return 0;
	long long max1=0,sum=0;
	for(int top1=fir[v];top1;top1=nex[top1])
		if(to[top1]!=u){
			ss(v,to[top1]);
			sum+=b[to[top1]];
			max1=max(max1,b[to[top1]]);
		}
	if(du[v]==1){
		b[v]=a[v];
	}
	else{
		if(a[v]*2<sum||a[v]>sum){
			flag=1;
			return 0;
		}
		if(max1>a[v]){
			flag=1;
			return 0;
		}
		b[v]=2*a[v]-sum;
	}
	return 0;
}
int main(){
	n=read();
	for(i=1;i<=n;i++)
		a[i]=read();
	if(n==2){
		if(a[1]==a[2])
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	for(i=1;i<n;i++){
		y=read();
		z=read();
		lj(y,z);
		lj(z,y);
		du[y]++;
		du[z]++;
	}
	for(i=1;i<=n;i++)
		if(du[i]!=1){
			ss(i,i);
			if(flag==0&&b[i]==0)
				printf("YES\n");
			else
				printf("NO\n");
			return 0;
		}
	return 0;
}