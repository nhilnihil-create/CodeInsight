#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
#define mid (l+r>>1)
int a[15],dig;
char c[14];
long long ans,digi[15];
bool check(long long x){
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",c);
	if(c[0]=='Y') return 1;
	return 0;
}
main(){
	digi[0]=1;dig=1;
	for(int i=1;i<=9;i++){
		digi[i]=digi[i-1]*10;
		printf("? %lld\n",digi[i]);
		fflush(stdout);
		scanf("%s",c);
		if(c[0]=='N') break;
		dig++;
	}
	if(dig==10){
		int len;
		for(len=0;len<9;++len){
			printf("? %lld\n",digi[len+1]-1);
			fflush(stdout);
			scanf("%s",c);
			if(c[0]=='Y') break;
		}
		printf("! %lld\n",digi[len]);
		fflush(stdout);return 0;
	}
	for(int i=1;i<=dig;++i){
		int l=i==1,r=9;
		while(l<r){
			if(check((ans+mid*digi[dig-i])*10+digi[dig-i+1]-1)) r=mid;
			else l=mid+1;
		}
		ans+=l*digi[dig-i];
	}
	printf("! %lld\n",ans);
	fflush(stdout);
	return 0;
}