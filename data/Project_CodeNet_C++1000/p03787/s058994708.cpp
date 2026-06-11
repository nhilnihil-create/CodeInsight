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
int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=1ll*x*x%p)if(k&1)res=1ll*res*x%p;return res;}
const int maxn=4e5+5;
ll pacnt;
int n,m,tot,flag,cnt;
int a1,a2,a3;
int head[maxn],des[maxn],nxt[maxn];
int col[maxn];
void adde(int x,int y){
	des[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}
void dfs(int x,int c){
	cnt++;
	col[x]=c;
	Rep(p,x){
		if(col[des[p]]==-1)dfs(des[p],!c);
		else if(col[des[p]]==c)flag=1;
	}
}
ll P(int x){
	return 1ll*x*x;
}
int main(){
	memset(col,-1,sizeof col);
	read(n);read(m);
	pacnt=1ll*n*n;
	rep(i,1,m){
		int x,y;read(x);read(y);
		adde(x,y);adde(y,x);
	}
	rep(i,1,n)if(col[i]==-1){
		if(!head[i])a3++;
		else{
			cnt=0;
			flag=0;
			dfs(i,0);
			if(flag)a2++;
			else a1++;
		}
	}
	ll ans=P(a1+a2+a3)+P(a1)+1ll*a3*(2*n-2*(a1+a2+a3));
	printf("%lld\n",ans);
	return 0;
}