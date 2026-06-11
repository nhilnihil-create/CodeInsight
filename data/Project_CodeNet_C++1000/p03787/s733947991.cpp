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
#define SZ 666666
int n,m,col[SZ]; Edg
bool dfs(int x)
{
	bool ok=1;
	for esb(x,e,b)
	{
		if(col[b]==-1) col[b]=!col[x],ok&=dfs(b);
		else if(col[b]==col[x]) ok=0;
	}
	return ok;
}
int main()
{
	memset(col,-1,sizeof col);
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	ll sg=0,pa=0,pb=0;
	for(int i=1;i<=n;++i)
		if(col[i]==-1)
		{
			col[i]=0;
			if(!fst[i]) ++sg;
			else if(dfs(i)) ++pa;
			else ++pb;
		}
	ll ans=sg*sg+2*sg*(n-sg)+(pa+pb)*(pa+pb)+pa*pa;
	printf("%lld\n",ans);
}
