#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 555555
int n,m,c[N];
int lowbit(int x){
	return x&(-x);
}
int sum(int x){
	int res=0;
	while (x){
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
void add(int x,int val){
	while (x<=n){
		c[x]+=val;
		x+=lowbit(x);
	}
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
struct pt{
	int l,r;
}a[N];
bool cmp(pt x,pt y){
	return x.r-x.l<y.r-y.l;
}
signed main(){
	while (scanf("%d%d",&m,&n)!=-1){
		memset(c,0,sizeof(c));
		for (int i=1;i<=m;++i){
			a[i].l=read();
			a[i].r=read();
		}
		sort(a+1,a+1+m,cmp);
		int j=0;
		for (int d=1;d<=n;++d){
			int tmp=0;
			for (int i=d;i<=n;i+=d){
				tmp+=sum(i);
			}
			printf("%d\n",tmp+m-j);
			while (j<m && a[j+1].r-a[j+1].l<=d){
				add(a[j+1].l,1);
				add(a[j+1].r+1,-1);
				j++;
			}
		}
	}
	return 0;
}