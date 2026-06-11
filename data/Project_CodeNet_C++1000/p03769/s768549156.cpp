/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define inf 1000000005
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define pa pair<int,int>
#define pb push_back
#define be begin()
#define en end()
#define ret return puts("-1"),0;
#define mod 1000000007
#define N 500055
#define int ll
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}inline void wrn(int a,int b,int c){wri(a);wrn(b,c);}
int n,m,a[N],num,tot,z[N],num1[N],vis[N];
signed main(){
	n=read();
	num1[0]=1;
	F(i,1,40) num1[i]=num1[i-1]*2;
	D(i,40,1) if (n&num1[i]) z[++tot]=i,vis[i]=tot;
	F(i,1,z[1]) a[i]=i;
	num=z[1];vis[z[1]]=0;
	D(i,tot,2) a[i-1+num]=i-1+z[1];
	num+=tot-1;
	F(i,1,z[1]){
		a[++num]=i;
		if (vis[i]) a[++num]=vis[i]-1+z[1];
	}
	a[++num]=99;a[++num]=99;
	if (n&1) a[++num]=100,a[++num]=100;
	wrn(num);
	F(i,1,num) wri(a[i]);
	return 0;
}