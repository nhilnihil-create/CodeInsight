#include<bits/stdc++.h>
#define il inline
#define rg register
using namespace std;
const int O=100010;
il int gi(){
	int o=0,fl=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')fl=-1,ch=getchar();
	while(isdigit(ch))o=o*10+ch-'0',ch=getchar();
	return fl*o;
}
int n,l,x[O],f[31][O];
int main(){
	n=gi();
	for(int i=1;i<=n;++i)x[i]=gi();
	l=gi();
	for(int i=1;i<=n;++i)f[0][i]=upper_bound(x+1,x+n+1,x[i]+l)-x-1;
	for(int j=1;j<31;++j)
		for(int i=1;i<=n;++i)
			f[j][i]=f[j-1][f[j-1][i]];
	for(int Q=gi();Q--;){
		int x=gi(),y=gi(),ans=0;
		if(x>y)x^=y^=x^=y;
		for(int j=30;~j;--j)
			if(f[j][x]<y)ans+=1<<j,x=f[j][x];
		printf("%d\n",ans+1);
	}
	return 0;
}
