/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define inf 1000000005
#define mod 1000000007
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define int ll
#define pa pair<int,int>
#define pb push_back
#define be begin()
#define en end()
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
int n,m,a[N],l2;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	n=read();
	F(i,1,n) a[i]=read();
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while (l<r){
		int mid=(l+r+1)>>1;
		if (a[mid]>=mid) l=mid;
		else r=mid-1;
	}
	r=l;
	F(i,l+1,n){
		if (a[i]>=l) r=i;
		else break;
	}
	l2=a[l]-l;
	if (l2%2==1||(r-l)%2==1) puts("First");
	else puts("Second");
	return 0;
}