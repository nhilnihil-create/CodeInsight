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
#define ret return puts("No"),0;
#define mod 1000000007
#define N 500055
//#define int ll
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
int n,m,a[N],tot;
struct xx{
	int x,i;
}z[N];
bool cmp(xx a,xx b){
	return a.x<b.x;
}
signed main(){
	n=read();
	F(i,1,n){
		z[i].x=read();z[i].i=i;
	}
	sort(z+1,z+n+1,cmp);
	F(i,1,n){
		if (z[i].x==z[i-1].x) ret;
		a[z[i].x]=z[i].i;
		F(j,1,z[i].i-1){
			tot++;
			while (a[tot]) tot++;
			a[tot]=z[i].i;
		}
		if (tot>z[i].x) ret;
	}
	tot=n*n+1;
	D(i,n,1){
		F(j,1,n-z[i].i){
			tot--;
			while (a[tot]) tot--;
			a[tot]=z[i].i;
		}
		if (tot<z[i].x) ret;
	}
	puts("Yes");
	F(i,1,n*n) wri(a[i]);
	return 0;
}