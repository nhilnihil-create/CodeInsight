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
#define S 4
int n,a[SZ];
ll f[S+1]; char o[SZ];
int main()
{
	memset(f,-127/3,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<n;++i)
		scanf("%d%s",a+i,o+i+1);
	scanf("%d",a+n);
	f[0]=0;
	for(int i=n;i>=2;--i)
	{
		for(int j=1;j<=S;++j)
			f[j]=max(f[j],f[j-1]);
		if(o[i]=='-')
		{
			for(int j=1;j<=S;++j) f[j-1]=max(f[j-1],f[j]);
			for(int j=0;j<=S;++j) f[j]-=(j&1)?(-a[i]):a[i];
		}
		else
			for(int j=0;j<=S;++j) f[j]+=(j&1)?(-a[i]):a[i];
	}
	printf("%lld\n",f[0]+a[1]);
}
