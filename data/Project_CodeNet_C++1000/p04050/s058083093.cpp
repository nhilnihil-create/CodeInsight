#include <iostream> //中文注释
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
int n,m,a[SZ];
bool oo(int a,int b) {return (a&1)<(b&1);}
int main()
{
	scanf("%d%d",&n,&m); int o=0;
	for(int i=1;i<=m;++i)
		scanf("%d",a+i),o+=a[i]&1;
	if(o>2)
	{
		puts("Impossible");
		return 0;
	}
	sort(a+1,a+1+m,oo);
	reverse(a+1,a+1+m);
	if(m>1) swap(a[2],a[m]);
	for(int i=1;i<=m;++i) printf("%d ",a[i]);
	puts("");
	vector<int> vs;
	if(m>1)
	{
		vs.pb(a[1]-1); vs.pb(2);
		for(int i=2;i<m;++i) vs.pb(a[i]);
		vs.pb(a[m]-1);
	}
	else
	{
		vs.pb(a[1]-1); vs.pb(1);
	}
	vector<int> r;
	for(int i=0;i<vs.size();++i)
		if(vs[i]) r.pb(vs[i]);
	vs=r;
	printf("%d\n",int(r.size()));
	for(int i=0;i<r.size();++i) printf("%d ",r[i]);
	puts("");
}