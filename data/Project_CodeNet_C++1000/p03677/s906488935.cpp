#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
struct P{
	int l,r,w;
	P(){}
	P(int a,int b,int c){l=a;r=b;w=c;}
}a[N<<1],b[N<<1];
int n,m,c[N];
ll ans=1e15,sum=0;
bool cmpl(P a,P b){
	return a.l<b.l;
}
bool cmpr(P a,P b){
	return a.r<b.r;
}
ll w[N];
int main(){
	scanf("%d%d",&n,&m);
	int tot=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(i>1){
			if(c[i]>c[i-1]){
				sum+=c[i]-c[i-1];
				a[++tot]=P(c[i-1]+1,c[i],0);
			}else{
				sum+=c[i]+m-c[i-1];
				a[++tot]=P(c[i-1]+1,m,0);
				a[++tot]=P(1,c[i],m-c[i-1]);
			}
		}
	}
	for(int i=1;i<=tot;i++) b[i]=a[i];
	sort(a+1,a+tot+1,cmpl);
	sort(b+1,b+tot+1,cmpr);
	w[0]=sum;
	for(int i=1,p=0,j=0,h=0;i<=m;i++){
		w[i]=w[i-1]-h;
		while(p<tot&&a[p+1].l==i){
			p++;
			w[i]-=a[p].w;
			h++;
		}
		ans=min(ans,w[i]);
		while(j<tot&&b[j+1].r==i){
			j++;
			w[i]+=b[j].w;
			w[i]+=b[j].r-b[j].l;
			h--;
		}
	}
	printf("%lld",ans);
	return 0;
}