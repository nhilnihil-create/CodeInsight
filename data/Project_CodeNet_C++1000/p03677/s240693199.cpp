#include <cstdio>
#include <cstring>
#define MAXN 100010
#define LL long long

int n,m;
LL v[MAXN];
LL d[MAXN][2];

void add(int l,int r,LL x1,LL x2){
	d[l][0]+=x1;
	d[l][1]+=x2;
	d[r+1][0]-=x1;
	d[r+1][1]-=x2;
}

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",v+i);
	LL s0=0;
	for(int i=1;i<n;i++){
		LL a=v[i],b=v[i+1];
		if(a<b){
			add(a+1,b,-1,a+1);
			s0+=b-a;
		}else{
			if(a<m) add(a+1,m,-1,a+1);
			add(1,b,-1,a-m+1);
			s0+=b+m-a;
		}
	}
	LL t0=0,t1=0;
	LL ans=1LL<<60;
	for(int i=1;i<=m;i++){
		t0+=d[i][0]; t1+=d[i][1];
		LL s=s0+t0*i+t1;
		if(s<ans) ans=s;
	}
	printf("%lld\n",ans);
}
