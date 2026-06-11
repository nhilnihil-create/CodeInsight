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

#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=2005,M=N*N+N+N,P=1e9+7;

int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }

int n,k,f[N][N],fac[M],inv[M];

int C(int n,int m){
	if(m<0||m>n)return 0;
	return mul(fac[n],mul(inv[m],inv[n-m])); 
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	fac[0]=1; lop(i,1,M)fac[i]=mul(fac[i-1],i); 
	inv[1]=1; lop(i,2,M)inv[i]=mul(P-P/i,inv[P%i]);
	inv[0]=1; lop(i,1,M)inv[i]=mul(inv[i-1],inv[i]); 

	cin>>n>>k;	
	if(--k==0){
		puts("1"); 
		return 0; 
	}
	f[0][0]=1;
	rep(i,0,n)rep(j,i,n){
		if(i+1<=n)f[i+1][j]=add(f[i+1][j],f[i][j]); 	
		if(j+1<=n)f[i][j+1]=add(f[i][j+1],mul(f[i][j],C(k-1+j*k+i+1-1,j*k+i+1-1)));
		//Pr("f[%d][%d]=%d\n",i,j,f[i][j]); 
	}
	printf("%d\n",mul(f[n][n],fac[n]));
	return 0;
}