#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 100005;

struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int n;
int a[N];
int d[N];
LL c[N];
bool ans;

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

LL maxll(LL x,LL y){
	return x>y?x:y;
}

bool bz[N];
int fa[N];

void dfs(int x){
	bz[x]=1;
	if (d[x]==1){c[x]=a[x];return;}
	for(int p=h[x];p;p=e[p].nxt)
	if (!bz[e[p].x]){
		fa[e[p].x]=x;
		dfs(e[p].x);
	}
	LL s=0,mv=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x){
		s+=c[e[p].x];
		mv=maxll(mv,c[e[p].x]);
	}
	LL k=s-a[x];
	if (k<0)ans=0;
	c[x]=s-k*2;
	if (c[x]<0)ans=0;
	if (mv>s/2&&s-mv<k)ans=0;
}

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
		d[x]++,d[y]++;
	}
	if (n==2){
		if (a[1]==a[2])printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int rt;
	fo(i,1,n)
	if (d[i]>1){rt=i;break;}
	ans=1;
	dfs(rt);
	ans&=(c[rt]==0);
	if (ans)printf("YES\n");
	else printf("NO\n");
	return 0;
}