#include<cstdio>
#define N 110000
inline char gc(){
	static char now[1<<16],*T,*S;
	if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
	return *S++;
} 
inline int read(){
	int x=0;char ch=gc();
	while (ch<'0'||ch>'9') ch=gc();
	while (ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=gc();}
	return x;
}
inline int gcd(int x,int y){
	if (y==0) return x;return gcd(y,x%y);
}
int cur,n,a[N],mod,g1[N],g2[N];long long sum;
void printans(){
	if (!cur) printf("Second");else printf("First");
}
int main(){
	//freopen("d.in","r",stdin);
	n=read();
	for (int i=1;i<=n;++i) a[i]=read(),(mod+=a[i]%2)%=2;
	if (n%2&&!mod) {printf("First");return 0;}
	if (!(n%2)) {if (mod) printf("First");else printf("Second");return 0;}
	while (1){sum=0;
		for (int i=1;i<=n;++i) g1[i]=gcd(a[i],g1[i-1]);
		for (int i=n;i>=1;--i) g2[i]=gcd(a[i],g2[i+1]);
		for (int i=1;i<=n;++i) sum+=a[i];int g;
		for (int i=1;i<=n;++i){
			if (a[i]==1) {printans();return 0;}
			g=gcd(g1[i-1],gcd(a[i]-1,g2[i+1]));
			if (((sum-1)/g)%2) break;
		}
		if (g==1) {printans();return 0;}
		for (int i=1;i<=n;++i) a[i]/=g;
		cur^=1;
	}
	return 0;
}