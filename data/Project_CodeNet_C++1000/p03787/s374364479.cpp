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

const int N = 100010;

int nxt[N];
int fa[N];
int n,m;
struct edge{
	int x,nxt;
}e[N*4];
int h[N],tot;
int s[N];
int label[N];
bool bz[N];

int getfather(int x){
	if (fa[x]==x)return x;
	return fa[x]=getfather(fa[x]);
}

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

bool dfs(int x,int lab){
	bool pd=1;
	s[x]=1;
	if (label[x]&&lab!=label[x])pd=0;
	else label[x]=lab;
	for(int p=h[x];p;p=e[p].nxt)
	if (!s[e[p].x]){
		pd&=dfs(e[p].x,lab%2+1);
		s[x]+=s[e[p].x];
	}
	else pd&=(label[e[p].x]!=lab);
	return pd;
}

int main(){
	n=get();m=get();
	fo(i,1,n)fa[i]=i;
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y);inse(y,x);
		x=getfather(x),y=getfather(y);
		if (x<y)fa[y]=x;else fa[x]=y;
	}
	LL ans=0;
	int cnt=0,cnt_single=0,cnt_bit=0;
	fo(i,1,n)
	if (getfather(i)==i){
		bz[i]=dfs(i,1);
		cnt++;
		if (s[i]==1)cnt_single++;
		else if (bz[i])cnt_bit++;
	}
	fo(i,1,n)
	if (fa[i]==i){
		if (s[i]==1)ans=ans+n;
		else{
			if (!bz[i])ans=ans+1ll*cnt_single*s[i]+cnt-cnt_single;
			else ans=ans+1ll*cnt_single*s[i]+cnt-cnt_single+cnt_bit;
		}
	}
	printf("%lld\n",ans);
	return 0;
}