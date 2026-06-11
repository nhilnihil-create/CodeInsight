#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,a[SZ],d[SZ],fe[SZ]; Edg
void dfs(int x,int f=0)
{
	if(d[x]==1)
	{
		fe[x]=a[x];
		return;
	}
	int g=a[x]+a[x];
	for esb(x,e,b) if(b!=f)
	{
		dfs(b,x),g-=fe[b];
		if(fe[b]>a[x])
		{
			puts("NO");
			exit(0);
		}
	}
	if(g<0||g>a[x])
	{
		puts("NO");
		exit(0);
	}
	fe[x]=g;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b); ++d[a],++d[b];
	}
	if(n==2)
	{
		if(a[1]==a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	int x=0;
	for(int i=1;i<=n;++i) if(d[i]>1) x=i;
	dfs(x);
	if(fe[x]!=0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
}
