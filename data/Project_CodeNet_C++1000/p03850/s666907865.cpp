#include<bits/stdc++.h>
#define N 100005
#define LL long long
using namespace std;

LL read(){
	char c=getchar();
	LL t=0,f=1;
	while(c>'9'||c<'0') f=(c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9') t=t*10+c-'0',c=getchar();
	return t*f;
}

int n,op[N],st;
LL sum[N],absum[N]; 
char ch[2];

int main(){
	n=read(),sum[1]=absum[1]=read(),st=op[1]=1;
	for(int i=2,x;i<=n;i++){
		scanf("%s",ch),op[i]=(ch[0]=='-')?-1:1;
		x=read(),sum[i]=sum[i-1]+x*op[i],absum[i]=absum[i-1]+x;
	}
	LL ans=sum[n];
	while(op[st]>0) st++;
	for(int i=2,j=3;i<=n;i=j,j++){
		if(op[i]>0 )continue;
		LL tmp=sum[i-1];
		while(op[j]>0&&j<=n) j++;
		tmp+=(absum[n]-absum[j-1])-(absum[j-1]-absum[i-1]);
		ans=max(ans,tmp);
	}
	printf("%lld\n",ans);
}
/*
3
5 - 1 - 3
5
1 - 20 - 13 + 14 - 5
6
3 - 5 + 1 + 6 - 11 - 13
*/