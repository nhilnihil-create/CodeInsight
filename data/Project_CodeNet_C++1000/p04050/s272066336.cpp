#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull usigned ll
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*t;
}
int n,m,tot,f[2],a[105];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),m=read(),f[0]=1,f[1]=m;
	for(int i=1;i<=m;i++){
		a[i]=read();
		if(!(a[i]&1))continue;
		f[tot++]=i;
		if(tot>2)return printf("Impossible"),0;
	}swap(a[1],a[f[0]]),swap(a[m],a[f[1]]);
	for(int i=1;i<=m;i++)printf("%d ",a[i]);printf("\n");
	if(m==1&&a[1]==1)return printf("1\n1"),0;
	if(m==1)return printf("2\n%d 1",a[1]-1),0;
	printf("%d\n",a[m]>1?m:m-1);
	printf("%d ",a[1]+1);
	for(int i=2;i<m;i++)printf("%d ",a[i]);
	if(a[m]>1)printf("%d",a[m]-1);
	return 0;
}