#include<bits/stdc++.h>
using namespace std;
const int nn=3e5,mm=1e5+1;
int n,m,dep,c[mm];
struct sou{int l,r,di;}ran[nn];
bool cmp(sou a,sou b){return a.di<b.di;}
int lowbit(int p){return p&(-p);}
int prefix(int i){
	int p=0;
	for(;i;i-=lowbit(i))p+=c[i];
	return p;
}void add(int i,int v){for(;i<=m;i+=lowbit(i))c[i]+=v;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&ran[i].l,&ran[i].r);
		ran[i].di=ran[i].r-ran[i].l;
	}sort(ran,ran+n,cmp);
	for(int i=1,ans;i<=m;i++){
		for(;dep<n&&ran[dep].di<i;dep++)add(ran[dep].l,1),add(ran[dep].r+1,-1);
		ans=n-dep;
		for(int j=i;j<=m;j+=i)ans+=prefix(j);
		printf("%d\n",ans);
	}return 0;
}