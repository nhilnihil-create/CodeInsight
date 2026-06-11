#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct data{
	int l,r;
	data(){}
	data(int x,int y):l(x),r(y){}
	friend bool operator<(const data &dt1,const data &dt2){return dt1.r-dt1.l+1<dt2.r-dt2.l+1;}
};

int N,M,sum[300001];
data dt[300001];

inline int lowbit(int x){return x&-x;}

int update(int k,int x){for(int i=k;i<=M+1;i+=lowbit(i))sum[i]+=x;}

int query(int x){int res=0;for(int i=x;i>0;i-=lowbit(i))res+=sum[i];return res;}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)scanf("%d%d",&dt[i].l,&dt[i].r);
	sort(dt+1,dt+N+1);
	for(int i=1,p=1;i<=M;++i){
		int ans=N-p+1;
		for(int j=1;i*j<=M;++j)ans+=query(i*j);
		printf("%d\n",ans);
		while(p<=N&&dt[p].r-dt[p].l+1<=i)update(dt[p].l,1),update(dt[p].r+1,-1),++p;
	}
}