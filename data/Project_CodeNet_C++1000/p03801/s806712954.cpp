#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100002;
struct node{
	int x,id;
}a[N];
int n,i,id[N],cnt,b[N],mx[N];
ll ans[N];
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int rd(){
	int x=0,fl=1;char ch=gc();
	for (;ch<48||ch>57;ch=gc())if(ch=='-')fl=-1;
	for (;48<=ch&&ch<=57;ch=gc())x=(x<<3)+(x<<1)+(ch^48);
	return x*fl;
}
inline void wri(ll a){if(a<0)a=-a,putchar('-');if(a>=10)wri(a/10);putchar(a%10|48);}
inline void wln(ll a){wri(a);puts("");}
bool cmp(node a,node b){return a.x<b.x || a.x==b.x && a.id<b.id;}
int main(){
	n=rd();
	for (i=1;i<=n;i++) a[i].x=rd(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	id[++cnt]=a[1].id;b[1]=1;mx[1]=a[1].x;
	for (i=2;i<=n;i++)
		if (a[i].x==a[i-1].x) b[cnt]++;
		else id[++cnt]=a[i].id,b[cnt]=1,mx[cnt]=a[i].x;
	for (i=cnt;i;i--) ans[id[i]]+=1ll*b[i]*(mx[i]-mx[i-1]),b[i-1]+=b[i],id[i-1]=min(id[i-1],id[i]);
	for (i=1;i<=n;i++) wln(ans[i]);
}