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
int n,a[SZ];
int gcd(int a,int b)
{return b?gcd(b,a%b):a;}
bool win()
{
	int ev=0,od=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]&1) ++od; else ++ev;
	}
	if(ev&1) return 1;
	if(od>1) return 0;
	int g=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]&1)
		{
			if(a[i]==1) return 0;
			--a[i];
		}
		g=gcd(g,a[i]);
	}
	for(int i=1;i<=n;++i) a[i]/=g;
	return !win();
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	if(win()) puts("First");
	else puts("Second");
}
