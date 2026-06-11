#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

typedef long long ll;

#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

const int N=505,M=N*N; 

struct P { int x,c; } a[N]; 
bool operator<(const P &a,const P &b) {
	return a.x<b.x; 
}

int fail,n,cnt[N],q[M],h,t,res[M]; 

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	scanf("%d",&n); 
	rep(i,1,n){
		scanf("%d",&a[i].x); 
		a[i].c=i;
	}
	sort(a+1,a+n+1); 
	int p=n;
	dec(i,n,1){
		lop(k,0,n-a[i].c)q[t++]=a[i].c;
		cnt[a[i].c]=n;
	}
	dec(i,n*n,1){
		if(p&&i==a[p].x){
			if(cnt[a[p].c]!=a[p].c)fail=true;
			res[i]=a[p].c;
			lop(k,1,a[p].c)q[t++]=a[p].c;
			--p;
		}else{
			if(h==t)fail=true;
			res[i]=q[h++];
			--cnt[res[i]]; 
		}
	}
	puts(fail?"No":"Yes"); 
	if(!fail)rep(i,1,n*n)printf("%d ",res[i]); puts(""); 
	return 0;
}