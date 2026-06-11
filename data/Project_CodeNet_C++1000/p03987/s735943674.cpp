#include<bits/stdc++.h>
#define rint register int
using namespace std;
inline int read(){
	int s=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return f?s:-s;
}
int n,a[200010],b[200010];
int f[200010][210];
long long ans;
void ST_prework(){
	for(rint i=1;i<=n;++i) f[i][0]=a[i];
	int t=log2(n)+1;
	for(rint j=1;j<t;++j)
		for(rint i=1;i<=n-(1<<j)+1;++i)
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
}
int ST_query(int l,int r){
	int k=log2(r-l+1);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
void sol(int l,int r){
	if(l>r) return;
	if(l==r){
		ans+=a[l];
		return;
	}
	int num=ST_query(l,r);
	ans+=1LL*(r-b[num]+1)*(b[num]-l+1)*num;
//		cout<<ans<<' '<<num1<<' '<<b[num1]<<' '<<l<<' '<<r<<' '<<endl;
	sol(l,b[num]-1); sol(b[num]+1,r);
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(rint i=1;i<=n;++i) a[i]=read(),b[a[i]]=i;
	ST_prework(); sol(1,n);
	printf("%lld",ans);
	return 0;
}