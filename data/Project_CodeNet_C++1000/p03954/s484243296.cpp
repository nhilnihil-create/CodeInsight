#include <bits/stdc++.h>
#define il inline
#define rg register
using namespace std;
typedef long long LL;
const LL m_63=1061109567;
const LL m_127=2139062143;
const LL inf=2147483647;
const LL llf=9223372036854775807;
const LL N=1e5+7;
const LL M=2e5+7;
LL n,a[M],id,ans[M],sum[M];
il LL read(){
	LL x(0),ff(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
il void write(LL x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
il void fre(){
	freopen("mid.in","r",stdin);
	freopen("mid.out","w",stdout);
}
il int check(int k){
	for(rg int i=0;i<n-1;++i){
		int x1=a[n+i],x2=a[n+i+1],y1=a[n-i],y2=a[n-i-1];
		if((x1<=k&&x2<=k)||(y1<=k&&y2<=k))return 1;
		if((x1>k&&x2>k)||(y1>k&&y2>k))return 0;
	}
	if(a[1]<=k)return 1;
	else if(a[1]>k)return 0;
}
int main(){
//	fre();
	n=read();
	for(rg LL i=1;i<2*n;++i)a[i]=read();
	int left=1,right=2*n-1,ans;
	while(left<right){
		int mid((left+right)>>1);
		if(check(mid))right=mid;
		else left=mid+1;
	}
	printf("%d",right);
	return 0;
}
/*
4
1 6 3 7 4 5 2
1 2 3 4 5 6 7
3 6 4
4 6 4
4 6 4 5
4 5 4 5
4 5 4 5 4
4 5 4 5 4


2 1 2 3
*/ 