//
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int n,x[MAXN],f[MAXN][20];

int binary_search(int k) {
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(x[mid]<=k) l=mid;
		else r=mid-1;
	}

	return r;
}

int main() {
	n=read();
	REP(i,1,n) x[i]=read();
	
	int l=read(),q=read();
	
	REP(i,1,n) f[i][0]=binary_search(x[i]+l);
	
	//DE("\n");REP(i,1,n) DE("%d ",f[i][0]);DE("\n");
	REP(j,1,16) REP(i,1,n) f[i][j]=f[f[i][j-1]][j-1];

	while(q--) {
		int a=read(),b=read();
		if(a>b) swap(a,b);
		int ans=0;
		DREP(i,16,0) {
			if(f[a][i]<b) a=f[a][i],ans+=(1<<i); 
		}

		printf("%d\n",ans+1);
	}
}