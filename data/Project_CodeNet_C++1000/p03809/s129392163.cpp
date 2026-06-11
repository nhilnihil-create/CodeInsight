#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
#define w1 first
#define w2 second
#define ls (x<<1)
#define rs (x<<1|1)
#define pb push_back
#define mid ((l+r)>>1)
#define SZ(x) ((x).size())
#define All(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)])
template<class T>void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
const int maxn=1e5+5;
int n,tot,flag,rt;
int d[maxn],a[maxn],head[maxn],des[maxn<<1],nxt[maxn<<1];
void adde(int x,int y){
	des[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
int dfs(int x,int fa){
	int tot=0,maxi=0;
	Rep(p,x)if(des[p]!=fa){
		int now=dfs(des[p],x);
		tot+=now;
		maxi=max(maxi,now);
	}
	if(d[x]==1)return a[x];
	int can=min(tot-maxi,tot/2);
	if(x!=rt){
		int need=tot-a[x];
		if(need<0||can<need)flag=1;
		return tot-2*need;
	}else{
		if(can*2!=tot||can!=a[x])flag=1;
	}
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,1,n-1){
		int x,y;read(x);read(y);
		adde(x,y);adde(y,x);
		d[x]++;d[y]++;
	}
	if(n==2){
		if(a[1]==a[2])puts("YES");
		else puts("NO");
		return 0;
	}
	rep(i,1,n)if(d[i]>1)rt=i;
	dfs(rt,0);
	if(flag)puts("NO");
	else puts("YES");
	return 0;
}