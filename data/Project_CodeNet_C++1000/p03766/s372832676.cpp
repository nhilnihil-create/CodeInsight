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
#define N 1000055
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
int n,m,f[N],sum[N],ans;
inline int get_s(int x){
	return (x>=0)?sum[x]:0;
}
inline void add(int &x,int k){
	x+=k;x-=(x>=mod)?mod:0;
}
signed main(){
	n=read();
	f[0]=1;sum[0]=1;
	F(i,1,n){
		f[i]=(f[i-1]+get_s(i-3))%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
	}
	F(i,0,n-2){
		add(ans,1LL*f[i]*(n-1)%mod*(n-1)%mod);
		add(ans,1LL*f[i]*(i+1)%mod);
	}
	add(ans,1LL*f[n-1]*(n-1)%mod);add(ans,f[n]);
	wrn(ans);
	return 0;
}