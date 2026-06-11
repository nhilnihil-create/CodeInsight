#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
struct data{
	int l,r,len;
	data(){}
	data(int l,int r):l(l),r(r),len(r-l+1){}
	int operator<(const data& d)const{return len<d.len;}
}d[maxn];
int tr[maxn],n,m;
void add(int x,int a){for(;x<=m;x+=x&-x)tr[x]+=a;}
int qry(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&d[i].l,&d[i].r),d[i].len=d[i].r-d[i].l+1;
	sort(d+1,d+n+1);
	for(int i=1,l=1;i<=m;++i){
		while(l<=n&&d[l].len<i)
			add(d[l].l,1),add(d[l].r+1,-1),l++;
		int ans=n-l+1;
		for(int j=i;j<=m;j+=i)
			ans+=qry(j);//,printf("[%d]",qry(j));
		printf("%d\n",ans);
	}
}