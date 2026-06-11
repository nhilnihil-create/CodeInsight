#pragma GCC optimize(3)
#include<iostream>
#include<iomanip>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#define ll long long
#define db double
#define inf 100001
#define INF (int)1e9
#define pi acos(-1)
#define rd(n) {n=0;char ch;int f=0;do{ch=getchar();if(ch=='-'){f=1;}}while(ch<'0'||ch>'9');while('0'<=ch&&ch<='9'){n=(n<<1)+(n<<3)+ch-48;ch=getchar();}if(f)n=-n;}
using namespace std;
int n,m;

int sum[inf*4],tag[inf*4];

void ST_pushdown(int u,int l,int r,int mid){
	if (tag[u]){
		int ls=u*2,rs=u*2+1;
		sum[ls]+=tag[u]*(mid-l+1);
		sum[rs]+=tag[u]*(r-mid);
		tag[ls]+=tag[u];
		tag[rs]+=tag[u];
		tag[u]=0;
	}
	return;
}

void ST_pushup(int u){
	sum[u]=sum[u*2]+sum[u*2+1];
	return;
}

void ST_modify(int u,int l,int r,int L,int R,int v){
	if (L<=l && r<=R){
		sum[u]+=(r-l+1)*v;
		tag[u]+=v;
		return;
	}
	int mid=(l+r)/2;
	ST_pushdown(u,l,r,mid);
	if (L<=mid){
		ST_modify(u*2,l,mid,L,R,v);
	}
	if (R>mid){
		ST_modify(u*2+1,mid+1,r,L,R,v);
	}
	ST_pushup(u);
	return;
}

int ST_query(int u,int l,int r,int k){
	if (l==r){
		return sum[u];
	}
	int mid=(l+r)/2;
	ST_pushdown(u,l,r,mid);
	if (k<=mid){
		return ST_query(u*2,l,mid,k);
	}
	else{
		return ST_query(u*2+1,mid+1,r,k);
	}
}

struct data{
	int l,r;
}a[inf*3];

bool operator<(data _1,data _2){
	return _1.r-_1.l+1<_2.r-_2.l+1;
}

int main(){
	rd(n) rd(m)
	for (int i=1;i<=n;i++){
		rd(a[i].l) rd(a[i].r)
	}
	sort(a+1,a+n+1);
	int pos=1;
	for (int i=1;i<=m;i++){
		while (pos<=n && a[pos].r-a[pos].l+1<i){
			ST_modify(1,0,m,a[pos].l,a[pos].r,1);
			pos++;
		}
		int ans=n-pos+1;
		for (int j=0;i*j<=m;j++){
			ans+=ST_query(1,0,m,i*j);
		}
		printf("%d\n",ans);
	}
	return 0;
}